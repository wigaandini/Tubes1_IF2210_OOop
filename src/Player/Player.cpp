#include "Player.hpp"
#include "../Game/Game.hpp"
#include "../Item/Building.hpp"

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
        cout << "Pilih makanan dari penyimpanan" << endl;
        this->inventory.displayStorage(false);
        bool success = false;
        while (!success)
        {
            cout << endl
                 << "Slot: ";
            string slot;
            cin >> slot;
            if (this->inventory.see(slot)->getItemId() == -1)
            {
                cout << endl
                     << "Kamu mengambil harapan kosong dari penyimpanan." << endl
                     << "Silahkan masukan slot yang berisi makanan." << endl;
            }
            else
            {
                if (Game::getProductConfig().find(this->inventory.see(slot)->getName()) != Game::getProductConfig().end() && Game::getProductConfig()[this->inventory.see(slot)->getName()].type != ProductType::PRODUCT_MATERIAL_PLANT)
                {
                    int x = Game::getProductConfig()[this->inventory.take(slot)->getName()].addedWeight;
                    cout << endl
                         << "Dengan lahapnya, kamu memakanan hidangan itu" << endl
                         << "Alhasil, berat badan kamu naik menjadi " << this->weight + x << endl;
                    success = true;
                }
                else
                {
                    cout << endl
                         << "Apa yang kamu lakukan?!! Kamu mencoba untuk memakan itu?!!" << endl
                         << "Silahkan masukan slot yang berisi makanan." << endl;
                }
            }
        }
    }
}

void Player::buy(shared_ptr<Item> &item, int quantity)
{
    if (item->getPrice() * quantity > this->gulden)
    {
        throw ""; // uang  tidak cukup
    }

    if (this->inventory.countEmpty() < quantity)
    {
        throw ""; // Penyimpanan tidak cukup
    }

    this->gulden -= item->getPrice() * quantity;
}

pair<vector<shared_ptr<Item>>, int> Player::sell(vector<string> &slots)
{
    pair<vector<shared_ptr<Item>>, int> items;
    items.second = 0;
    for (string slot : slots)
    {

        if (this->inventory.isEmpty(slot))
        {
            throw "Empty slot"; // empty slot
        }

        if (shared_ptr<Building> building = dynamic_pointer_cast<Building>(this->inventory.see(slot)))
        {
            throw "Tidak bisa jual bangunan"; // Tidak bisa jual bangunan
        }
    }

    for (string slot : slots)
    {

        const shared_ptr<Item> &item = this->inventory.take(slot);
        this->gulden += item->getPrice();
        items.second += item->getPrice();
        items.first.push_back(item);
    }

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

