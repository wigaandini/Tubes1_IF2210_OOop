#ifndef _GRID_HPP_
#define _GRID_HPP_
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
    void parseInput(string s, int &intt, char &charr) const;

    void parseInput(string s, int &row, int &col) const;


public:
    Grid(int r, int c);

    ~Grid();

    vector<vector<shared_ptr<T>>> &getBuffer();

    int getRow() const;

    int getCol() const;

    bool isFull();

    bool isEmpty();

    bool isEmpty(const string &slot);

    int countEmpty() const;

    int countOccupied() const;

    void operator+(const shared_ptr<T> item);

    shared_ptr<T> &see(int i, int j);

    void remove(int i, int j);

    void put(string slot, const shared_ptr<T> val);

    shared_ptr<T> take(string slot);

    void remove(string slot);

    shared_ptr<T> &see(string slot);

    template <class U>
    friend ostream &operator<<(ostream &os, const Grid<U> &g);
};

#include "Grid.tpp"

#endif