#ifndef __PLANTCONFIG_HPP_
#define __PLANTCONFIG_HPP_

#include <string>
using namespace std;

enum PlantType {
    MATERIAL_PLANT,
    FRUIT_PLANT
};

class PlantConfig {
    public :
        int id;
        string name;
        PlantType type;
        string code;
        int durationToHarvest;
        int price;
};

#endif