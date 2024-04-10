#include "Mayor.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Game/Game.hpp"
#include "../Farmer/Farmer.hpp"
#include <algorithm>
#include "MayorException.hpp"

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

// int Mayor::getWealth()
// {
//     return 0;
// }

string Mayor::toLower(string s)
{
    string snew;
    for (char c : s)
    {
        snew += tolower(c);
    }
    return snew;
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

// bool Mayor::canBuild(string buildingName)
// {
//     auto itr = find_if(Game::getRecipe().begin(), Game::getRecipe().end(), [buildingName](pair<string, RecipeConfig> building)
//                        { return buildingName == building.second.name; });
//     if (itr != Game::getRecipe().end())
//     {
//         map<string, int> availableMaterials;
//         for (auto material : itr->second.materials)
//         {
//             availableMaterials[material.first] = 0;
//             for (int i = 0; i < this->inventory.getRow(); i++)
//             {
//                 for (int j = 0; j < this->inventory.getcol(); j++)
//                 {
//                     if (this->inventory.see(i, j)->getName() == material.first)
//                     {
//                         availableMaterials[material.first]++;
//                     }
//                 }
//             }
//             availableMaterials[material.first] -= material.second;
//         }

//         auto checkNegItr = find_if(availableMaterials.begin(), availableMaterials.end(), [](pair<string, int> material)
//                                    { return material.second < 0; });
//         if (checkNegItr != availableMaterials.end() || gulden < itr->second.price)
//         {
//             cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
//             if (gulden < itr->second.price)
//             {
//                 cout << itr->second.price - gulden << " gulden ";
//             }
//             if (checkNegItr != availableMaterials.end())
//             {
//                 for (auto availableMaterial : availableMaterials)
//                 {
//                     if (availableMaterial.second < 0)
//                     {
//                         cout << availableMaterial.second * -1 << " " << availableMaterial.first << " ";
//                     }
//                 }
//             }
//             cout << "!" << endl;
//             return false;
//         }
//         // Kasus ketika SDA cukup untuk membangun building
//         gulden -= itr->second.price;
//         for (auto material : itr->second.materials)
//         {
//             for (int k = 0; k < material.second; k++)
//             {
//                 for (int i = 0; i < inventory.getRow(); i++)
//                 {
//                     for (int j = 0; j < inventory.getcol(); j++)
//                     {
//                         if (this->inventory.see(i, j)->getName() == material.first)
//                         {
//                             inventory.remove(i, j);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     else
//     {
//         cout << "Kamu tidak punya resep bangunan tersebut!" << endl;
//         cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
//         for (auto itr = Game::getRecipe().begin(); itr != Game::getRecipe().end(); itr++)
//         {
//             cout << "   " << itr->second.id << ". " << itr->second.name << "(" << itr->second.price << " gulden, ";
//             int ctr = 0;
//             for (auto material : itr->second.materials)
//             {
//                 cout << material.first << " " << material.second;
//                 if (ctr < int(itr->second.materials.size()))
//                 {
//                     cout << ",";
//                 }
//                 ctr++;
//             }
//             cout << ")" << endl;
//         }
//         return false;
//     }
//     return true;
// }

// void Mayor::canBuild(string buildingName)
// {
//     auto itr = find_if(Game::getRecipe().begin(), Game::getRecipe().end(), [buildingName](pair<string, RecipeConfig> building)
//                        { return buildingName == building.second.name; });
//     if (itr != Game::getRecipe().end())
//     {
//         map<string, int> notEnoughMaterials;
//         if (this->gulden < Game::getRecipe()[buildingName].price)
//         {
//             notEnoughMaterials["gulden"] = Game::getRecipe()[buildingName].price - this->gulden;
//         }
//         for (auto material : itr->second.materials)
//         {
//             int count = this->inventory.countItemStock(material.first);
//             if (count < material.second)
//             {
//                 notEnoughMaterials[material.first] = material.second - count;
//             }
//         }

//         if (notEnoughMaterials.size() > 0)
//         {
//             throw NotEnoughMaterialException(notEnoughMaterials);
//         }

//         // Kasus ketika SDA cukup untuk membangun building
//         this->gulden -= itr->second.price;
//         for (auto material : itr->second.materials)
//         {

//             this->inventory.useItem(material.first, material.second);
//         }
//     }
//     else
//     {
//         throw NoRecipeException();
//     }
// }

void Mayor::buildBuilding()
{

    cout << Game::getRecipe() << endl;
    string buildingName;
    bool isValid = false;
    while (!isValid)
    {
        try
        {
            cout << "Bangunan yang ingin dibangun: ";
            cin >> buildingName;

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
    cout << buildingName << "berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
    inventory.putRandom(make_shared<Building>(buildingName));
}

void Mayor::addPlayer()
{
    if (gulden >= 50)
    {
        string playerType;
        string playerName;
        cout << "Masukkan jenis pemain: ";
        cin >> playerType;
        playerType = toLower(playerType);
        cout << "Masukkan nama pemain: ";
        cin >> playerName;
        auto itr = find_if(Game::getPlayers().begin(), Game::getPlayers().end(), [&playerName, this](auto player)
                           { return toLower(player->getName()) == toLower(playerName); });
        if (itr == Game::getPlayers().end())
        {
            shared_ptr<Player> newPlayer;
            if (playerType == "peternak")
            {
                newPlayer = make_shared<Breeder>(playerName, 40, 50);
            }
            else if (playerType == "petani")
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
            cout << "Pemain dengan nama " << playerName << "telah terdaftar!" << endl;
        }
    }
    else
    {
        cout << "Uang tidak cukup!" << endl;
    }
}

int Mayor::tax()
{
    return 0;
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
            throw ""; // empty slot
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