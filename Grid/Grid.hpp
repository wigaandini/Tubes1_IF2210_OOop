#ifndef __GRID_HPP_
#define __GRID_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
using namespace std;

template <class T>
class Grid {
    private:
        vector<map<string, T>> buffer;
        int col;
        int row;
    public:
        Grid();
        Grid(int col, int row);
        Grid(const Grid &grid);
        ~Grid();
        void put(string key, T value);
        T get(string key);
        void remove(string key);
        T see(string key);
        friend ostream& operator<<(ostream &os, Grid<T> &grid);
};


#endif