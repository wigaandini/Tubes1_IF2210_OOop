#ifndef __INVENTORY_HPP_
#define __INVENTORY_HPP_

#include "../Grid/Grid.hpp"
#include "../Item/Item.hpp"
#include "../Item/Product.hpp"
#include <functional>

class Inventory : public Grid<Item>
{
private:
    template <class T>
    bool checkInventoryItemType(function<bool(const T &)> checkType, map<string, T> config)
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                if (this->buffer[i][j] != nullptr)
                {
                    auto configUse = config.find(this->buffer[i][j]->getName());
                    if (configUse != config.end() && checkType(configUse->second))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    Inventory(int r, int c, Item defaultValue);
    Inventory();
    ~Inventory();
    void displayStorage(bool printInfo);
    bool checkInventoryEdible();
    bool checkInventoryAnimal();
    bool checkInventoryPlant();
    int countItemStock(const Item &name);
    void useItem(const Item &, int);
    bool isInventoryEnough(const int &);
    void putRandom(const shared_ptr<Item>);

    bool checkInventoryFruit();
    bool checkInventoryMeat();
    int countInventoryItem();
};

#endif