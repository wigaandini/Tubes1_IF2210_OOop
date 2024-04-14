#ifndef __FARM_HPP_
#define __FARM_HPP_

#include "../SpecializedGrid/SpecializedGrid.hpp"
#include "../Item/Plant.hpp"
#include <map>
using namespace std;

class Farm : public SpecializedGrid<Plant> {
public:
    Farm(int r, int c, Plant defaultValue);
    Farm();
    ~Farm();
    void displayStorage(bool printInfo);
    // bool checkPlantReadyToHarvest();
    // map<string, int> countPlant();
    void addPlantAge();
};

#endif 