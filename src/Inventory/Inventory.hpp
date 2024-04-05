#include "../Grid/Grid.hpp"
template<class T>
class Inventory: public Grid<T>{
    public:
        Inventory(int r, int c, T defaultValue): Grid<T>(r, c, defaultValue){}
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