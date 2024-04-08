#include "Player.hpp"
#include "../Game/Game.hpp"

int Player::countIdPlayer = 1;

Player::Player()
{
    this->playerId = countIdPlayer++;
    this->username = "anonim";
    this->weight = 40;
    this->gulden = 50;
    Item i;

    this->inventory = new Inventory(Game::getMainConfig().inventorySize[0], Game::getMainConfig().inventorySize[1], i);
}

Player::Player(string username, int weight, int gulden)
{
    this->playerId = countIdPlayer++;
    this->username = username;
    this->weight = weight;
    this->gulden = gulden;
    Item i;
    this->inventory = new Inventory(Game::getMainConfig().inventorySize[0], Game::getMainConfig().inventorySize[1], i);
    countIdPlayer++;
}

Player::~Player()
{
    delete this->inventory;
}

void Player::eat()
{
    if (this->inventory->isEmpty())
    {
        cout << "Inventory anda kosong" << endl;
    }
    else if (!this->inventory->checkInventoryEdible())
    {
        cout << "Inventory anda tidak ada yang dapat dimakan" << endl;
    }
    else
    {
        cout << "Pilih makanan dari penyimpanan" << endl;
        this->inventory->displayStorage(false);
        bool success = false;
        while (!success)
        {
            cout << endl
                 << "Slot: ";
            string slot;
            cin >> slot;
            if (this->inventory->see(slot).getItemId() == -1)
            {
                cout << endl
                     << "Kamu mengambil harapan kosong dari penyimpanan." << endl
                     << "Silahkan masukan slot yang berisi makanan." << endl;
            }
            else
            {
                if (Game::getProductConfig().find(this->inventory->see(slot).getName()) != Game::getProductConfig().end() && Game::getProductConfig()[this->inventory->see(slot).getName()].type != ProductType::PRODUCT_MATERIAL_PLANT)
                {
                    int x = Game::getProductConfig()[this->inventory->take(slot).getName()].addedWeight;
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

string Player::getName(){
    return username;
}

int Player::getGulden(){
    return gulden;
}

int Player::getWeight(){
    return weight;
}

void Player::setGulden(int gulden){
    this->gulden = gulden;
}

void Player::buy()
{
}

void Player::sell()
{
}
