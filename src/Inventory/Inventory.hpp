#ifndef __INVENTORY_HPP_
#define __INVENTORY_HPP_

#include "../Grid/Grid.hpp"
#include "../Item/Item.hpp"

class Inventory: public Grid<Item> {
public:
    Inventory(int r, int c, Item defaultValue);
    Inventory();
    ~Inventory();
    void displayStorage(bool printInfo);
    bool checkInventoryEdible();
    bool checkInventoryAnimal();
    bool checkInventoryPlant();

    void putRandom(const shared_ptr<Item> );

    bool checkInventoryFruit();
    bool checkInventoryMeat();
};

#endif