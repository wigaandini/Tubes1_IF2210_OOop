#include "Farmer.hpp"
#include "../Game/Game.hpp"
#include "../Utils/Utils.hpp"
#include "../Grid/Grid.hpp"
#include <limits>

Farmer::Farmer() : Resident()
{
    type = "Petani";
}

Farmer::Farmer(string username, int weight, int gulden) : Resident(username, weight, gulden)
{
    type = "Petani";
}

Farmer::~Farmer()
{
}

void Farmer::plant()
{
    Resident::placeTo<Farm, PlantConfig, Plant>(
        this->farm, Game::getPlantConfig(), [this]()
        { return this->inventory.checkInventoryPlant(); },
        "Ladang");
}

// void Farmer::buy(shared_ptr<Item> &item, int quantity)
// {
//     if (item->getPrice() * quantity > this->gulden)
//     {
//         throw ""; // uang  tidak cukup
//     }

//     if (this->inventory.countEmpty() < quantity)
//     {
//         throw ""; // Penyimpanan tidak cukup
//     }

//     this->gulden -= item->getPrice() * quantity;
// }

// vector<shared_ptr<Item>> Farmer::sell(vector<string> &slots)
// {
//     vector<shared_ptr<Item>> items;
//     for (string slot : slots)
//     {

//         if (this->inventory.isEmpty(slot))
//         {
//             throw ""; // empty slot
//         }

//         if (shared_ptr<Building> building = dynamic_pointer_cast<Building>(this->inventory.see(slot))){
//             throw ""; //Tidak bisa jual bangunan
//         }
//     }

//     for (string slot : slots)
//     {

//         const shared_ptr<Item> &item = this->inventory.take(slot);
//         this->gulden += item->getPrice();
//         items.push_back(item);
//     }

//     return items;
// }

void Farmer::harvest()
{

    Resident::harvest<Farm, PlantConfig>(this->farm, Game::getPlantConfig(), Plant::getHarvestResult(), "Ladang");
}

int Farmer::getWealth()
{
    int wealth = gulden;
    for (int i = 0; i < this->inventory.getRow(); i++)
    {
        for (int j = 0; j < this->inventory.getCol(); j++)
        {
            if (this->inventory.see(i, j) != nullptr)
            {
                wealth += this->inventory.see(i, j)->getPrice();
            }
        }
    }
    for (int i = 0; i < this->farm.getRow(); i++)
    {
        for (int j = 0; j < this->farm.getCol(); j++)
        {
            if (this->farm.see(i, j) != nullptr)
            {
                wealth += this->farm.see(i, j)->getPrice();
            }
        }
    }
    return wealth;
}

int Farmer::calculateTax()
{
    int kkp = getWealth() - KTKP_PETANI;
    if (kkp <= 0)
    {
        return 0;
    }
    else
    {
        if (kkp <= 6)
        {
            return 0.05 * kkp;
        }
        else if (kkp <= 25 && kkp > 6)
        {
            return 0.15 * kkp;
        }
        else if (kkp <= 50 && kkp > 25)
        {
            return 0.25 * kkp;
        }
        else if (kkp <= 500 && kkp > 50)
        {
            return 0.30 * kkp;
        }
        else
        {
            return 0.35 * kkp;
        }
    }
}

Farm &Farmer::getFarm()
{
    return this->farm;
}

void Farmer::saveFile(const string &filepath)
{
    ofstream file(filepath, ios::app);

    file << username << " Petani " << weight << " " << gulden << endl;

    Inventory &inventoryItems = Resident::Player::getInventory();
    file << inventoryItems.countInventoryItem() << endl;
    for (int i = 0; i < inventoryItems.getRow(); i++)
    {
        for (int j = 0; j < inventoryItems.getCol(); j++)
        {
            if (inventoryItems.see(i, j) != nullptr)
            {
                file << inventoryItems.see(i, j)->getName() << endl;
            }
        }
    }

    Farm &farmItems = getFarm();
    file << farmItems.countOccupied() << endl;
    for (int j = 0; j < farmItems.getCol(); j++)
    {
        for (int i = 0; i < farmItems.getRow(); i++)
        {
            if (farmItems.see(i, j) != nullptr)
            {
                shared_ptr<Plant> plant = farmItems.see(i, j);
                file << char('A' + j);
                if (i + 1 < 10)
                {
                    file << '0' << i + 1 << " " << plant->getName() << " " << plant->getAge() << endl;
                }
                else
                {
                    file << i + 1 << " " << plant->getName() << " " << plant->getAge() << endl;
                }
            }
        }
    }

    file.close();
}