#ifndef __SLOT_HPP_
#define __SLOT_HPP_

#include "../Grid/Grid.hpp"
#include <map>
using namespace std;

class Slot : public Grid<string> {
public:
    Slot();
    ~Slot();
    void displaySlot(vector<string> result);
};

#endif 