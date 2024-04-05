#include "../Grid/Grid.hpp"
#include "../Item/Plant.hpp"
class Farm: public Grid<Plant>{
    public:
        Farm(int r, int c, Plant defaultValue): Grid<Plant>(r, c, defaultValue){}
        ~Farm(){};
        void displayStorage(bool printInfo){
            string title = "[ Ladang ]";
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
                
            }
        }
};