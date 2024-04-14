#ifndef _SPECIALIZED_GRID_HPP_
#define _SPECIALIZED_GRID_HPP_

#include <string>
#include <iostream>
#include "../Grid/Grid.hpp"
#include "../PColor/pcolor.h"

using namespace std;

template <class T>
class SpecializedGrid : public Grid<T>
{

public:
    SpecializedGrid(int r, int c) : Grid<T>(r, c){};
    void displayStorage(const string &title)
    {
        string printTitle = "[ " + title + " ]";
        int columnWidthWithBorders = 6;
        int totalGridWidth = this->col * columnWidthWithBorders;
        int equalsLength = (totalGridWidth - printTitle.length()) / 2;
        string equalsSide(equalsLength, '=');
        cout << "     " << equalsSide << printTitle << equalsSide;
        if ((totalGridWidth - printTitle.length()) % 2 != 0)
        {
            cout << "=";
        }
        cout << "=\n";
        cout << "    ";
        for (int j = 0; j < this->col; ++j)
        {
            cout << setw(5) << static_cast<char>('A' + j) << " ";
        }
        cout << "\n";
        cout << "     ";
        for (int j = 0; j < this->col; ++j)
        {
            cout << "+-----";
        }
        cout << "+\n";

        for (int i = 0; i < this->row; ++i)
        {
            cout << setw(2) << setfill(' ') << (i + 1) << "   |";
            for (int j = 0; j < this->col; ++j)
            {

                cout << " " << setw(2) << setfill(' ');
                if (this->buffer[i][j] != nullptr)
                {
                    string name = this->buffer[i][j]->getCode();

                    if (!this->buffer[i][j]->checkReadyToHarvest())
                    {
                        for (char ch : name)
                        {
                            print_red(ch);
                        }
                        cout << "|";
                    }
                    else if (this->buffer[i][j]->checkReadyToHarvest())
                    {
                        for (char ch : name)
                        {
                            print_green(ch);
                        }
                        cout << "|";
                    }
                }
                else
                {
                    cout << "   ";
                    cout << " |";
                }
            }
            cout << endl;
            cout << "     ";
            for (int j = 0; j < this->col; ++j)
            {
                cout << "+-----";
            }
            cout << "+\n";
        }
        cout << endl
             << endl;
    };
    bool checkReadyToHarvest()
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                if (this->buffer[i][j] != nullptr && this->buffer[i][j]->checkReadyToHarvest())
                {
                    return true;
                }
            }
        }
        return false;
    };
    map<string, int> countItemsReadyToHarvest()
    {
        map<string, int> itemCount;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                if (this->buffer[i][j] != nullptr && this->buffer[i][j]->checkReadyToHarvest())
                {
                    string itemName = this->buffer[i][j]->getName();
                    itemCount[itemName]++;
                }
            }
        }
        return itemCount;
    };
};

#endif