#include "Mayor.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Game/Game.hpp"
#include "../Farmer/Farmer.hpp"
#include <algorithm>
#include <random>
#include "MayorException.hpp"
#include "../Player/PlayerException.hpp"
using namespace std;

Mayor::Mayor() : Player()
{
    type = "Walikota";
}

Mayor::Mayor(string username, float weight, int gulden) : Player(username, weight, gulden)
{
    type = "Walikota";
}

Mayor::~Mayor() {}


void Mayor::taxCollection()
{
    vector<shared_ptr<Resident>> residents;
    int tax, sumTax = 0;
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl
         << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;

    for (auto &player : Game::getPlayers())
    {
        shared_ptr<Resident> resident = dynamic_pointer_cast<Resident>(player);

        if (resident != nullptr)
        {
            residents.push_back(resident);
        }
    }

    sort(residents.begin(), residents.end(), [](auto a, auto b)
         {
        if(a->getWealth() == b->getWealth()){
            return a->getName() < b->getName();
        }
        return a->getWealth() > b->getWealth(); });

    for (int i = 0; i < int(residents.size()); i++)
    {
        shared_ptr<Resident> &resident = residents[i];
        cout << "    " << i + 1 << ". " << residents[i]->getName() << " - " << residents[i]->getType() << ": ";
        tax = (resident->getGulden() >= resident->calculateTax()) ? resident->calculateTax() : resident->getGulden(); // Bayar pajak semampunya
        cout << tax << " gulden" << endl;
        resident->setGulden(resident->getGulden() - tax);
        sumTax += tax;
    }
    cout << "Negara mendapatkan pemasukan sebesar " << sumTax << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
    gulden += sumTax;
}

void Mayor::buildBuilding()
{
    cout << Game::getRecipe() << endl;
    string buildingName;
    bool isValid = false;
    while (!isValid)
    {
        try
        {
            cout << "Bangunan yang ingin dibangun (Ketik q untuk keluar): ";
            cin >> buildingName;
            if (buildingName == "q")
            {
                break;
            }
            auto itr = find_if(Game::getRecipe().begin(), Game::getRecipe().end(), [buildingName](pair<string, RecipeConfig> building)
                               { return buildingName == building.second.name; });
            if (itr != Game::getRecipe().end())
            {
                map<string, int> notEnoughMaterials;
                if (this->gulden < Game::getRecipe()[buildingName].price)
                {
                    notEnoughMaterials["gulden"] = Game::getRecipe()[buildingName].price - this->gulden;
                }
                for (auto material : itr->second.materials)
                {
                    int count = this->inventory.countItemStock(Item(material.first, Game::getProductConfig()[material.first].code, Game::getProductConfig()[material.first].price));
                    if (count < material.second)
                    {
                        notEnoughMaterials[material.first] = material.second - count;
                    }
                }

                if (notEnoughMaterials.size() > 0)
                {
                    throw NotEnoughMaterialException(notEnoughMaterials);
                }

                // Kasus ketika SDA cukup untuk membangun building
                this->gulden -= itr->second.price;
                for (auto material : itr->second.materials)
                {

                    this->inventory.useItem(Item(material.first, Game::getProductConfig()[material.first].code, Game::getProductConfig()[material.first].price), material.second);
                }
            }
            else
            {
                throw NoRecipeException();
            }

            isValid = true;
        }
        catch (NotEnoughMaterialException &e)
        {
            cout << e.what() << endl;
        }
        catch (NoRecipeException &e)
        {
            cout << e.what() << endl;
            cout << Game::getRecipe() << endl;
        }
    }
    if (isValid)
    {
        cout << buildingName << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
        inventory + make_shared<Building>(buildingName);
    }
}

void Mayor::addPlayer()
{
    if (gulden >= 50)
    {
        string playerType;
        string playerName;
        cout << "Masukkan jenis pemain: ";
        cin >> playerType;
        if(playerType != "Peternak" && playerType != "Petani" && playerType != "petani" && playerType != "peternak"){
            cout << "Jenis permain tersebut tidak ditemukan!" << endl;
            return;
        }
        cout << "Masukkan nama pemain: ";
        cin >> playerName;
        auto itr = find_if(Game::getPlayers().begin(), Game::getPlayers().end(), [&playerName](auto player)
                           { return player->getName() == playerName; });
        if (itr == Game::getPlayers().end())
        {
            shared_ptr<Player> newPlayer;
            if (playerType == "Peternak" || playerType == "peternak")
            {
                newPlayer = make_shared<Breeder>(playerName, 40, 50);
            }
            else if (playerType == "Petani" || playerType == "petani")
            {
                newPlayer = make_shared<Farmer>(playerName, 40, 50);
            }
            Game::getPlayers().push_back(newPlayer);
            gulden -= 50;
            cout << "Pemain baru ditambahkan!" << endl;
            cout << "Selamat datang \"" << playerName << "\" di kota ini!" << endl;
            sort(Game::getPlayers().begin(), Game::getPlayers().end(), [](const auto &a, const auto &b)
                 { return a->getName() < b->getName(); });
        }
        else
        {
            cout << "Pemain dengan nama " << playerName << " telah terdaftar!" << endl;
        }
    }
    else
    {
        cout << "Uang tidak cukup!" << endl;
    }
}

void Mayor::buy(shared_ptr<Item> &item, int quantity)
{
    cout << "Terdapat opsi dalam pembayaran: " << endl;
    cout << "1. Bayar dengan harga normal" << endl;
    cout << "2. Coin Flip (Jika benar maka barang gratis, Jika salah maka harga menjadi 2x)" << endl << endl;
    bool ben = false;
    int answer;

    while (!ben){
        cout << "Masukkan pilihan opsi pembayaran: ";
        cin >> answer;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus berupa angka. Silahkan coba lagi." << endl;
            continue;
        }

        if (answer == 1){
            ben = true;
            if (item->getPrice() * quantity > this->gulden)
            {
                throw NotEnoughGuldenException(); // uang  tidak cukup
            }

            if (shared_ptr<Building> building = dynamic_pointer_cast<Building>(item))
            {
                throw CannotBuyBuildingException(); // tidak bisa beli building
            }

            if (this->inventory.countEmpty() < quantity)
            {
                throw InventoryNotEnoughException(); // Penyimpanan tidak cukup
            }

            this->gulden -= item->getPrice() * quantity;

        } else if (answer == 2){
            ben = true;
            cout << endl << "Silahkan pilih angka 1 atau 2" << endl;
            int pilihan;
            int lower_bound = 1; 
            int upper_bound = 2;
            bool ben2 = false;
            
            while(!ben2){
                cout << "Masukkan angka pilihan: ";
                cin >> pilihan;

                if (cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input harus berupa angka. Silahkan coba lagi." << endl;
                    continue;
                }

                if (pilihan > 2 || pilihan < 1){
                    cout << "Masukan salah silahkah masukan kembali!!!" << endl;
                } else {
                    ben2 = true;
                // Inisialisasi generator angka acak dengan seed dari waktu saat ini
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<> dist(lower_bound, upper_bound);

                    // Menghasilkan angka acak dan mencetaknya
                    int random_number = dist(gen);
                    cout << endl << "Koin dilempar" << endl;
                    cout << "ting ting ting" << endl << "ting ting ting" << endl << "ting ting ting" << endl;
                    if (random_number != pilihan){
                        cout << endl << "Angka pilihan salah, harga menjadi 2x lipat" << endl;
                        if (item->getPrice() * quantity * 2 > this->gulden)
                        {
                            throw NotEnoughGuldenException(); // uang  tidak cukup
                        }

                        if (shared_ptr<Building> building = dynamic_pointer_cast<Building>(item))
                        {
                            throw CannotBuyBuildingException(); // tidak bisa beli building
                        }

                        if (this->inventory.countEmpty() < quantity)
                        {
                            throw InventoryNotEnoughException(); // Penyimpanan tidak cukup
                        }
                        this->gulden -= item->getPrice() * quantity * 2;

                    } else {
                        cout << endl << "Angka pilihan benar, anda beruntung" << endl;
                        if (shared_ptr<Building> building = dynamic_pointer_cast<Building>(item))
                        {
                            throw CannotBuyBuildingException(); // tidak bisa beli building
                        }

                        if (!this->inventory.isInventoryEnough(quantity))
                        {
                            throw InventoryNotEnoughException(); // Penyimpanan tidak cukup
                        }
                    }
                }
            }
        } else {
            cout << "Masukan salah silahkah masukan kembali!!!" << endl;
        }
    }
}

pair<vector<shared_ptr<Item>>, int> Mayor::sell(vector<string> &slots)
{
    pair<vector<shared_ptr<Item>>, int> items;
    items.second = 0;

    try
    {

        for (string slot : slots)
        {

            const shared_ptr<Item> &item = this->inventory.take(slot);
            if (item != nullptr)
            {
                items.second += item->getPrice();
                items.first.push_back(item);
            }
        }
    }
    catch (const SlotEmptyException &e)
    {
        for (unsigned int  i = 0 ; i < items.first.size(); i++){
            this->inventory.put(slots[i], items.first[i]);
        }
        throw ;
    }
    this->gulden += items.second;
    return items;
}

void Mayor::saveFile(const string& filepath){
    ofstream file(filepath, ios::app);
    file << username << " Walikota " << weight << " " << gulden << endl;

    Inventory &inventoryItems = Resident::Player::getInventory();
    file << inventoryItems.countInventoryItem() << endl;
    for (int i = 0; i < inventoryItems.getRow(); i++) {
        for (int j = 0; j < inventoryItems.getCol(); j++) {
            if (inventoryItems.see(i, j) != nullptr) {
                file << inventoryItems.see(i, j)->getName() << endl;
            }
        }
    }

    file.close();
}