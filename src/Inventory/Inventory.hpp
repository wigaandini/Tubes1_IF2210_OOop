#ifndef INVENTORY_HPP
#define INVENTORY_HPP

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
};

#endif