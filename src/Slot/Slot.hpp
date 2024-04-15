#ifndef __SLOT_HPP_
#define __SLOT_HPP_

#include "../Grid/Grid.hpp"
#include <map>
using namespace std;

class Slot : public Grid<string> {
private:
vector<string> prize;

public:
    Slot();
    ~Slot();
    void displaySlot();
    pair<int, string> play();
};

#endif 