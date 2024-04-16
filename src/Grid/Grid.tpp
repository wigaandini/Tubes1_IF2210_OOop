#include "Grid.hpp"
#include "GridException.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

template <class T>
void Grid<T>::parseInput(string s, int &intt, char &charr) const
{
    if (s.length() < 2 || !std::isupper(s[0]))
    {
        throw InvalidSlotFormatException();
    }
    try
    {

        charr = s[0];
        intt = stoi(s.substr(1));
    }
    catch (const exception &e)
    {
        throw InvalidSlotFormatException();
    }
};

template <class T>
void Grid<T>::parseInput(string s, int &row, int &col) const
{
    if (s.length() < 2 || !std::isupper(s[0]))
    {
        throw InvalidSlotFormatException();
    }
    try
    {
        char colTemp = s[0];
        row = stoi(s.substr(1));
        col = colTemp - 'A';
    }
    catch (const exception &e)
    {
        throw InvalidSlotFormatException();
    }
};

template <class T>
Grid<T>::Grid(int r, int c) : row(r), col(c), emptySlot(r * c)
{
    buffer.resize(row, vector<shared_ptr<T>>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            buffer[i][j] = nullptr;
        }
    }
};

template <class T>
Grid<T>::~Grid(){

};

template <class T>
vector<vector<shared_ptr<T>>> &Grid<T>::getBuffer()
{
    return this->buffer;
};

template <class T>
int Grid<T>::getRow() const
{
    return this->row;
};

template <class T>
int Grid<T>::getCol() const
{
    return this->col;
};

template <class T>
bool Grid<T>::isFull()
{
    return emptySlot == 0;
}

template <class T>
bool Grid<T>::isEmpty()
{
    return emptySlot == row * col;
};

template <class T>
bool Grid<T>::isEmpty(const string &slot)
{
    int rowIdx;
    int colIdx;
    this->parseInput(slot, rowIdx, colIdx);
    if (rowIdx <= 0 || rowIdx > row || colIdx < 0 || colIdx >= col)
    {
        throw IndexOutOfBoundException(slot);
    }
    return (this->buffer[rowIdx - 1][colIdx] == nullptr);
};

template <class T>
int Grid<T>::countEmpty() const
{
    return emptySlot;
};

template <class T>
int Grid<T>::countOccupied() const
{
    return row * col - emptySlot;
}

template <class T>
void Grid<T>::operator+(const shared_ptr<T> item)
{
    if (isFull())
    {
        throw GridFullException();
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (this->buffer[i][j] == nullptr)
            {
                this->buffer[i][j] = item;
                emptySlot--;
                return;
            }
        }
    }
};

template <class T>
shared_ptr<T> &Grid<T>::see(int i, int j)
{
    return buffer[i][j];
};

template <class T>
void Grid<T>::remove(int i, int j)
{
    buffer[i][j] = nullptr;
    emptySlot++;
};

template <class T>
void Grid<T>::put(string slot, const shared_ptr<T> val)
{
    if (emptySlot == 0)
    {
        throw GridFullException();
    }
    int x;
    char y;
    parseInput(slot, x, y);
    int colIdx = y - 'A';
    if (x <= 0 || x > row || colIdx < 0 || colIdx >= col)
    {
        throw IndexOutOfBoundException(slot);
    }
    if (buffer[x - 1][colIdx] == nullptr)
    {
        buffer[x - 1][colIdx] = val;
        emptySlot--;
    }
    else
    {
        throw SlotOccupiedException(slot);
    }
};

template <class T>
shared_ptr<T> Grid<T>::take(string slot)
{
    if (emptySlot == row * col)
    {
        throw GridEmptyException();
    }
    int x;
    char y;
    parseInput(slot, x, y);
    int colIdx = y - 'A';
    if (x <= 0 || x > row || colIdx < 0 || colIdx >= col)
    {
        throw IndexOutOfBoundException(slot);
    }
    if (!buffer[x - 1][colIdx])
    {
        throw SlotEmptyException(slot);
    }
    shared_ptr<T> val = buffer[x - 1][colIdx];
    buffer[x - 1][colIdx] = nullptr;
    emptySlot++;
    return val;
};

template <class T>
void Grid<T>::remove(string slot)
{

    if (emptySlot == row * col)
    {
        throw GridEmptyException();
    }
    int x;
    char y;
    parseInput(slot, x, y);
    int colIdx = y - 'A';
    if (x <= 0 || x > row || colIdx < 0 || colIdx >= col)
    {
        throw IndexOutOfBoundException(slot);
    }
    if (buffer[x - 1][colIdx] == nullptr)
    {
        throw SlotEmptyException(slot);
    }
    buffer[x - 1][colIdx] = nullptr;
    emptySlot++;
};

template <class T>
shared_ptr<T> &Grid<T>::see(string slot)
{
    int x;
    char y;
    parseInput(slot, x, y);
    int colIdx = y - 'A';
    if (x <= 0 || x > row || colIdx < 0 || colIdx >= col)
    {
        throw IndexOutOfBoundException(slot);
    }
    if (buffer[x - 1][colIdx] == nullptr)
    {
        throw SlotEmptyException(slot);
    }
    return (buffer[x - 1][colIdx]);
};

template <class T>
ostream &operator<<(ostream &os, const Grid<T> &g)
{
    // Cetak header kolom
    os << "    ";
    for (int j = 0; j < g.col; ++j)
    {
        os << setw(5) << (char)('A' + j) << " ";
    }
    os << "\n";

    // Cetak garis pemisah
    os << "     ";
    for (int j = 0; j < g.col; ++j)
    {
        os << "+-----";
    }
    os << "+\n";

    // Cetak isi grid
    for (int i = 0; i < g.row; ++i)
    {
        // Cetak nomor baris
        os << setw(2) << setfill('0') << (i + 1) << "   |";
        for (int j = 0; j < g.col; ++j)
        {
            // Cetak isi selpe
            if (g.buffer[i][j] != nullptr)
            {
                os << " " << setw(3) << setfill(' ') << *g.buffer[i][j] << " |";
            }
            else
            {
                os << " " << setw(3) << setfill(' ') << "   "
                   << " |";
            }
        }
        os << "\n";

        // Cetak garis pemisah setelah setiap baris
        os << "     ";
        for (int j = 0; j < g.col; ++j)
        {
            os << "+-----";
        }
        os << "+\n";
    }
    return os;
};