#ifndef _ANIMALCONFIG_HPP_
#define _ANIMALCONFIG_HPP_

#include <string>
using namespace std;

enum class AnimalType{
    HERBIVORE,
    CARNIVORE,
    OMNIVORE
};

class AnimalConfig{
public:
    int id;
    string name;
    AnimalType type;
    string code;
    int price;
    int weightToHarvest;
};

#endif