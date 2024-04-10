#ifndef _GRID_HPP_
#define _GRID_HPP_

#include "GridException.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

template <class T>
class Grid
{
protected:
    vector<vector<shared_ptr<T>>> buffer;
    int row;
    int col;
    int emptySlot;
    T defaultValue;
    void parseInput(string s, int &intt, char &charr) const;
    void parseInput(string s, int &row, int &col) const;

public:
    Grid(int r, int c, T defaultValue);
    Grid(int r, int c);
    ~Grid();
    int getRow() const;
    int getcol() const;
    bool isEmpty();
    int countEmpty() const;
    shared_ptr<T> see(int i, int j) const;
    void remove(int i, int j);
    void put(string slot, const shared_ptr<T> val);
    shared_ptr<T> take(string slot);
    void remove(string slot);
    T &see(string slot);
    friend ostream &operator<<(ostream &os, const Grid &g);
};

#endif