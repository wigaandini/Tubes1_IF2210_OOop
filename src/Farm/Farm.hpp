#ifndef __FARM_HPP_
#define __FARM_HPP_

#include "../SpecializedGrid/SpecializedGrid.hpp"
#include "../Item/Plant.hpp"
#include <map>
using namespace std;

class Farm : public SpecializedGrid<Plant> {
public:
    Farm(int r, int c);
    Farm();
    ~Farm();
    void displayStorage(bool printInfo);
    void addPlantAge();
};

#endif 