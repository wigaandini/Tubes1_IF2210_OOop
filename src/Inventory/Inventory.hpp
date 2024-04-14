#ifndef __INVENTORY_HPP_
#define __INVENTORY_HPP_

#include "../Grid/Grid.hpp"
#include "../Item/Item.hpp"
#include "../Item/Product.hpp"

class Inventory: public Grid<Item> {
public:
    Inventory(int r, int c, Item defaultValue);
    Inventory();
    ~Inventory();
    void displayStorage(bool printInfo);
    bool checkInventoryEdible();
    bool checkInventoryAnimal();
    bool checkInventoryPlant();
    int countItemStock(const Item&);
    void useItem(const Item&, int);
    bool isInventoryEnough(const int&);
    void putRandom(const shared_ptr<Item> );

    bool checkInventoryFruit();
    bool checkInventoryMeat();
    int countInventoryItem();
};

#endif