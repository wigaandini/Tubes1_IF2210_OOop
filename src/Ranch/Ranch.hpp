#ifndef __RANCH_HPP_
#define __RANCH_HPP_

#include "../SpecializedGrid/SpecializedGrid.hpp"
#include "../Item/Animal.hpp"
using namespace std;

class Ranch: public SpecializedGrid<Animal> {
public:
    Ranch(int r, int c);
    Ranch();
    ~Ranch();
    void displayStorage(bool printInfo);
    int countAnimalType();
};

#endif
