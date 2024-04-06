#ifndef __FARM_HPP_
#define __FARM_HPP_

#include "../Grid/Grid.hpp"
#include "../Item/Plant.hpp"
#include "../PColor/pcolor.h"
using namespace std;

class Farm : public Grid<Plant> {
public:
    Farm(int r, int c, Plant defaultValue);
    ~Farm();
    void displayStorage(bool printInfo);
    bool checkAnyReadyToHarvest();
};

#endif 