#include "Player.hpp"
#include "../Game/Game.hpp"
#include "../Item/Building.hpp"
#include "../Slot/Slot.hpp"
#include "PlayerException.hpp"
#include <random>

int Player::countIdPlayer = 1;

Player::Player()
{
    this->playerId = -1;
    this->username = "anonim";
    this->weight = 40;
    this->gulden = 50;
}

Player::Player(string username, int weight, int gulden)
{
    this->playerId = countIdPlayer++;
    this->username = username;
    this->weight = weight;
    this->gulden = gulden;
    this->inventory = Inventory();
    countIdPlayer++;
}

Player::~Player()
{
}

void Player::eat()
{

    if (this->inventory.isEmpty())
    {
        cout << "Inventory anda kosong" << endl;
    }
    else if (!this->inventory.checkInventoryEdible())
    {
        cout << "Inventory anda tidak ada yang dapat dimakan" << endl;
    }
    else
    {

        bool success = false;
        while (!success)
        {
            try
            {
                cout << "Pilih makanan dari penyimpanan" << endl;
                this->inventory.displayStorage(false);
                cout << endl
                     << "Slot (ketik q untuk keluar): ";
                string slot;
                cin >> slot;

                if (slot == "q")
                {
                    cout << "Tidak jadi makan!!!" << endl;
                    return;
                }

                if (dynamic_pointer_cast<Product>(this->inventory.see(slot)) && (Game::getProductConfig()[this->inventory.see(slot)->getName()].type == ProductType::PRODUCT_FRUIT_PLANT || Game::getProductConfig()[this->inventory.see(slot)->getName()].type == ProductType::PRODUCT_ANIMAL))
                {
                    int weight = Game::getProductConfig()[this->inventory.take(slot)->getName()].addedWeight;
                    cout << endl
                         << "Dengan lahapnya, kamu memakanan hidangan itu" << endl
                         << "Alhasil, berat badan kamu naik menjadi " << this->weight + weight << endl;
                    this->weight += weight;
                    success = true;
                }
                else
                {
                    cout << endl
                         << "Apa yang kamu lakukan?!! Kamu mencoba untuk memakan itu?!!" << endl
                         << "Silahkan masukan slot yang berisi makanan." << endl;
                }
            }
            catch (SlotEmptyException &e)
            {
                cout << endl
                     << "Kamu mengambil harapan kosong dari penyimpanan." << endl
                     << "Silahkan masukan slot yang berisi makanan." << endl
                     << endl;
            }
            catch (exception &e)
            {
                cout << e.what() << endl
                     << endl;
            }
        }
    }
}

string Player::getType(){
    return type;
}

bool Player::operator==(const Player &other)
{
    return this->username == other.username && this->playerId == other.playerId;
}

void Player::buy(shared_ptr<Item> &item, int quantity, int bonus)
{
    
    if (item->getPrice() * quantity * bonus > this->gulden)
    {
        throw NotEnoughGuldenException(); // Uang  tidak cukup
    }

    if (!this->inventory.isInventoryEnough(quantity))
    {
        throw InventoryNotEnoughException(); // Penyimpanan tidak cukup
    }

    this->gulden -= item->getPrice() * quantity * bonus;
}

pair<vector<shared_ptr<Item>>, int> Player::sell(vector<string> &slots)
{
    pair<vector<shared_ptr<Item>>, int> items;
    items.second = 0;

    try
    {

        for (string slot : slots)
        {

            if (shared_ptr<Building> building = dynamic_pointer_cast<Building>(this->inventory.see(slot)))
            {
                throw CannotSellBuildingException();
            }

            const shared_ptr<Item> &item = this->inventory.take(slot);
            items.second += item->getPrice();
            items.first.push_back(item);
        }
    }
    catch (const exception &e)
    {
        for (unsigned int i = 0; i < items.first.size(); i++)
        {
            this->inventory.put(slots[i], items.first[i]);
        }
        throw;
    }

    this->gulden += items.second;

    return items;
}

// vector<shared_ptr<Item>> Player::sell(vector<string>& slots)
// {
//     vector<shared_ptr<Item>> items;
//     for (string slot : slots) {

//         if (this->inventory.isEmpty(slot)){
//             throw ""; //empty slot
//         }
//     }

//     for (string slot : slots) {

//         const shared_ptr<Item>& item = this->inventory.take(slot);
//         this->gulden += item->getPrice();
//         items.push_back(item);
//     }

//     return items;
// }

string &Player::getName()
{
    return username;
}

int &Player::getGulden()
{
    return gulden;
}

int &Player::getWeight()
{
    return weight;
}

void Player::setGulden(int gulden)
{
    this->gulden = gulden;
}

Inventory &Player::getInventory()
{
    return this->inventory;
}

void Player::playSlot(){
    bool isAnswerValid = false;
    while (!isAnswerValid)
    {
        string answerState = "";
        cout << "=================================================\n";
        cout << "           Selamat Datang di Mesin Slot!         \n";
        cout << "=================================================\n";
        cout << "           Mulai Permainan dengan 1 Gulden       \n";
        cout << "   Berpeluang untuk Meraih Berbagai Keuntungan!  \n";
        cout << "-------------------------------------------------\n";
        cout << "Peraturan Permainan:\n";
        cout << "- Jika Anda mendapatkan 3 huruf 'A' yang sama, Anda memenangkan 10 gulden.\n";
        cout << "- Jika Anda mendapatkan 3 huruf 'B' yang sama, Anda memenangkan 20 gulden.\n";
        cout << "- Jika Anda mendapatkan 3 huruf 'C' yang sama, Anda memenangkan 30 gulden.\n";
        cout << "=================================================\n";
        cout << "Permainan ini memakai 1 gulden\n";
        cout << "Apakah Anda ingin bermain mesin slot? (Y/N) ";

        cin >> answerState;
        
        Slot s;
        if (answerState == "Y")
        {
            isAnswerValid = true;
            this->gulden --;
            vector<string> prize = {"A", "B", "C"};
            vector<string> slot;

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dist(0, 2);

            for (int i = 0; i < 3; i++){ 
                int random = dist(gen);
                slot.push_back(prize[random]);
            }

            cout << endl;
            s.displaySlot(slot);
            cout << endl;
            map<std::string, int> symbolCounts;
            for (const auto& symbol : slot) {
                ++symbolCounts[symbol];
            }
            if (symbolCounts["A"] == 3) {
                cout << "Selamat! Anda mendapatkan 3 simbol 'A' dan memenangkan 10 gulden!" << endl;
                this->gulden += 10;
            } else if (symbolCounts["B"] == 3) {
                cout << "Selamat! Anda mendapatkan 3 simbol 'P' dan memenangkan 20 gulden!" << endl;
                this->gulden += 20;
            } else if (symbolCounts["C"] == 3) {
                cout << "Selamat! Anda mendapatkan 3 simbol 'B' dan memenangkan 30 gulden!" << endl;
                this->gulden += 30;
            }else  {
                cout << "Maaf, Anda belum beruntung kali ini. Coba lagi!" << endl;
            }
        }
        else if (answerState == "N")
        {
            cout << endl << "Terima kasih telah mengunjungi!" << endl;
            return;
        }
        else
        {
            cout << "Masukan salah silahkan ulangi kembali!!" << endl;
        }
    }
}