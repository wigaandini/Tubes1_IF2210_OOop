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
    void parseInput(string s, int &intt, char &charr) const
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
    void parseInput(string s, int &row, int &col) const
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

public:
    Grid(int r, int c, T defaultValue) : row(r), col(c), emptySlot(r * c), defaultValue(defaultValue)
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
    Grid(int r, int c) : row(r), col(c), emptySlot(r * c)
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
    ~Grid(){

    };
    vector<vector<shared_ptr<T>>>& getBuffer() {
        return this->buffer;
    };
    int getRow() const
    {
        return this->row;
    };
    int getCol() const
    {
        return this->col;
    };

    bool isFull()
    {
        return emptySlot == 0;
    }

    bool isEmpty()
    {
        return emptySlot == row * col;
    };
    bool isEmpty(const string &slot)
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
    int countEmpty() const
    {
        return emptySlot;
    };
    int countOccupied() const{
        return row*col - emptySlot;
    }
    void operator+(const shared_ptr<T>& item)
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

    // bool isSlotEmpty(string slot)
    // {
    //     int x;
    //     char y;
    //     parseInput(slot, x, y);
    //     int colIdx = y - 'A';
    //     if (x <= 0 || x >= row || colIdx < 0 || colIdx >= col)
    //     {
    //         throw IndexOutOfBoundException();
    //     }

    //     return (buffer[x - 1][colIdx] == nullptr);
    // }
    shared_ptr<T> &see(int i, int j)
    {
        return buffer[i][j];
    };
    void remove(int i, int j)
    {
        buffer[i][j] = nullptr;
        emptySlot++;
    };
    void put(string slot, const shared_ptr<T> val)
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
    shared_ptr<T> take(string slot)
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
    void remove(string slot)
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
    shared_ptr<T> &see(string slot)
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

    friend ostream &operator<<(ostream &os, const Grid &g)
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
};

#endif