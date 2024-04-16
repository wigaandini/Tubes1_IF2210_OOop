#include "Inventory.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Constructor
Inventory::Inventory(int r, int c) : Grid<Item>(r, c) {}

Inventory::Inventory() : Grid(Game::getMainConfig().inventorySize[0], Game::getMainConfig().inventorySize[1])
{
}

Inventory::~Inventory()
{
}

int Inventory::countItemStock(const Item &item)
{
    int count = 0;
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            if (this->buffer[i][j] != nullptr)
            {
                if (*(this->buffer[i][j]) == item)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

void Inventory::useItem(const Item &item, int quantity)
{
    for (int k = 0; k < quantity; k++)
    {
        bool itemRemoved = false;
        for (int i = 0; i < this->row && !itemRemoved; i++)
        {
            for (int j = 0; j < this->col && !itemRemoved; j++)
            {
                if (this->buffer[i][j] != nullptr)
                {
                    if (*(this->buffer[i][j]) == item)
                    {
                        this->remove(i, j);
                        itemRemoved = true;
                    }
                }
            }
        }
    }
}

// Member function displayStorage
void Inventory::displayStorage(bool printInfo)
{
    string title = "[ Penyimpanan ]";
    int columnWidthWithBorders = 6;
    int totalGridWidth = this->col * columnWidthWithBorders;
    int equalsLength = (totalGridWidth - title.length()) / 2;
    string equalsSide(equalsLength, '=');
    cout << "     " << equalsSide << title << equalsSide;
    if ((totalGridWidth - title.length()) % 2 != 0)
    {
        cout << "=";
    }
    cout << "=\n";
    cout << (*this);
    if (printInfo)
    {
        cout << "Total slot kosong: " << this->emptySlot << endl;
    }
}

bool Inventory::isInventoryEnough(const int &quantity)
{
    if (quantity > this->emptySlot)
    {
        return false;
    }

    return true;
}

bool Inventory::checkInventoryEdible()
{
    return checkInventoryItemType<ProductConfig>(
        [](const ProductConfig &config)
        { return config.type == ProductType::PRODUCT_FRUIT_PLANT || config.type == ProductType::PRODUCT_ANIMAL; },
        Game::getProductConfig());
}

bool Inventory::checkInventoryAnimal()
{
    return checkInventoryItemType<AnimalConfig>(
        [](const AnimalConfig &config)
        { return config.type == AnimalType::HERBIVORE || config.type == AnimalType::CARNIVORE || config.type == AnimalType::OMNIVORE; },
        Game::getAnimalConfig());
}

bool Inventory::checkInventoryPlant()
{
    return checkInventoryItemType<PlantConfig>(
        [](const PlantConfig &config)
        { return config.type == PlantType::MATERIAL_PLANT || config.type == PlantType::FRUIT_PLANT; },
        Game::getPlantConfig());
}



bool Inventory::checkInventoryFruit()
{
    return checkInventoryItemType<ProductConfig>(
        [](const ProductConfig &config)
        { return config.type == ProductType::PRODUCT_FRUIT_PLANT; },
        Game::getProductConfig());
}

bool Inventory::checkInventoryMeat()
{
    return checkInventoryItemType<ProductConfig>(
        [](const ProductConfig &config)
        { return config.type == ProductType::PRODUCT_ANIMAL; },
        Game::getProductConfig());
}

int Inventory::countInventoryItem()
{
    int count = 0;
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            if (this->buffer[i][j] != nullptr)
            {
                count++;
            }
        }
    }
    return count;
}