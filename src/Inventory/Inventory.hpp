#include "../Grid/Grid.hpp"
#include "../Item/Item.hpp"

class Inventory: public Grid<Item>{
    public:
        Inventory(int r, int c, Item defaultValue): Grid<Item>(r, c, defaultValue){}
        ~Inventory(){};
        void displayStorage(bool printInfo){
            string title = "[ Penyimpanan ]";
            int columnWidthWithBorders = 6; 
            int totalGridWidth = this->col * columnWidthWithBorders;
            int equalsLength = (totalGridWidth - title.length()) / 2;
            string equalsSide(equalsLength, '=');
            cout << "     " << equalsSide << title << equalsSide;
            if ((totalGridWidth - title.length()) % 2 != 0) {
                cout << "=";
            }
            cout << "=\n";
            cout << (*this);
            if(printInfo){
                cout << "Total slot kosong: " << this->emptySlot << endl;
            }
        }
};