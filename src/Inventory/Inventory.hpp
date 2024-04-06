#ifndef __INVENTORY_HPP_
#define __INVENTORY_HPP_

#include "../Grid/Grid.hpp"
#include "../Item/Item.hpp"
#include <string>
#include <iostream>

class Inventory: public Grid<Item> {
public:
    Inventory(int r, int c, Item defaultValue);
    ~Inventory();
    void displayStorage(bool printInfo);
    bool checkInventoryEdible();
    bool checkInventoryAnimal();
    bool checkInventoryPlant();

    void putRandom(const Item& );

    bool Inventory::checkInventoryFruit();
    bool Inventory::checkInventoryMeat();
};

#endif