#ifndef __FARM_HPP_
#define __FARM_HPP_

#include "../Grid/Grid.hpp"
#include "../Item/Plant.hpp"
#include "../PColor/pcolor.h"
#include <map>
using namespace std;

class Farm : public Grid<Plant> {
public:
    Farm(int r, int c, Plant defaultValue);
    ~Farm();
    void displayStorage(bool printInfo);
    bool checkPlantReadyToHarvest();
    map<string, int> countPlant();
};

#endif 