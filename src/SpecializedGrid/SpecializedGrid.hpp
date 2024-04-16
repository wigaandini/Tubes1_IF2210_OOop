#ifndef _SPECIALIZED_GRID_HPP_
#define _SPECIALIZED_GRID_HPP_

#include <string>
#include <iostream>
#include "../Grid/Grid.hpp"

using namespace std;


template <class T>
class SpecializedGrid : public Grid<T>
{

public:
    SpecializedGrid(int r, int c);
    ~SpecializedGrid();
    void displayStorage(const string &title);
    bool checkReadyToHarvest();
    map<string, int> countItemsReadyToHarvest();
};

#include "SpecializedGrid.tpp"

#endif