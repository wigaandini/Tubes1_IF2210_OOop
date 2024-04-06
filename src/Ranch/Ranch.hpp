#ifndef __RANCH_HPP_
#define __RANCH_HPP_

#include "../Grid/Grid.hpp"
#include "../Item/Animal.hpp"
#include "../PColor/pcolor.h"
using namespace std;

class Ranch: public Grid<Animal> {
public:
    Ranch(int r, int c, Animal defaultValue);
    ~Ranch();
    void displayStorage(bool printInfo);
    bool checkAnyReadyToHarvest();
};

#endif
