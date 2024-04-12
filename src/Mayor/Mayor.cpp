#include "Mayor.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Game/Game.hpp"
#include "../Farmer/Farmer.hpp"
#include <algorithm>
#include "MayorException.hpp"
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

string Mayor::getType()
{
    return type;
}


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
        tax = (resident->getGulden() >= resident->tax()) ? resident->tax() : resident->getGulden(); // Bayar pajak semampunya
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
            if(buildingName == "q"){
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
                    int count = this->inventory.countItemStock(material.first);
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

                    this->inventory.useItem(material.first, material.second);
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
    if(isValid){
        cout << buildingName << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
        inventory.putRandom(make_shared<Building>(buildingName));
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
        if(playerType != "Peternak" && playerType != "Petani"){
            cout << "Jenis permain tersebut tidak ditemukan!" << endl;
            return;
        }
        playerType = playerType;
        cout << "Masukkan nama pemain: ";
        cin >> playerName;
        auto itr = find_if(Game::getPlayers().begin(), Game::getPlayers().end(), [&playerName, this](auto player)
                           { return player->getName() == playerName; });
        if (itr == Game::getPlayers().end())
        {
            shared_ptr<Player> newPlayer;
            if (playerType == "Peternak")
            {
                newPlayer = make_shared<Breeder>(playerName, 40, 50);
            }
            else if (playerType == "Petani")
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
    if (item->getPrice() * quantity > this->gulden)
    {
        throw ""; // uang  tidak cukup
    }

    if (shared_ptr<Building> building = dynamic_pointer_cast<Building>(item))
    {
        throw ""; // tidak bisa beli building
    }

    if (this->inventory.countEmpty() < quantity)
    {
        throw ""; // Penyimpanan tidak cukup
    }

    this->gulden -= item->getPrice() * quantity;
}

pair<vector<shared_ptr<Item>>, int> Mayor::sell(vector<string> &slots)
{
    pair<vector<shared_ptr<Item>>, int> items;
    items.second = 0;
    for (string slot : slots)
    {

        if (this->inventory.isEmpty(slot))
        {
            throw "Empty slot"; // empty slot
        }
    }

    for (string slot : slots)
    {

        const shared_ptr<Item> &item = this->inventory.take(slot);
        if(item != nullptr){
            this->gulden += item->getPrice();
            items.second += item->getPrice();
            items.first.push_back(item);
        }
    }

    return items;
}