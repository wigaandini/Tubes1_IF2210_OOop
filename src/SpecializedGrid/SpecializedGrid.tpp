#include "SpecializedGrid.hpp"
#include "../PColor/pcolor.hpp"

using namespace std;

template <class T>
SpecializedGrid<T>::SpecializedGrid(int r, int c) : Grid<T>(r, c){};

template <class T>
void SpecializedGrid<T>::displayStorage(const string &title)
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

template <class T>
SpecializedGrid<T>::~SpecializedGrid(){

}

template <class T>
bool SpecializedGrid<T>::checkReadyToHarvest()
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
template <class T>
map<string, int> SpecializedGrid<T>::countItemsReadyToHarvest()
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