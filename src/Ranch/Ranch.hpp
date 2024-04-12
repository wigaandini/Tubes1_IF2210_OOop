#ifndef __RANCH_HPP_
#define __RANCH_HPP_

#include "../Grid/Grid.hpp"
#include "../Item/Animal.hpp"
using namespace std;

class Ranch: public Grid<Animal> {
public:
    Ranch(int r, int c, Animal defaultValue);
    Ranch();
    ~Ranch();
    void displayStorage(bool printInfo);
    bool checkAnimalReadyToHarvest();
    map<string, int> countAnimal();
    int countAnimalType();
};

#endif
