#include "../Grid/Grid.hpp"
#include "../Item/Animal.hpp"
class Ranch: public Grid<Animal>{
    public:
        Ranch(int r, int c, Animal defaultValue): Grid<Animal>(r, c, defaultValue){}
        ~Ranch(){};
        void displayStorage(bool printInfo){
            string title = "[ Peternakan ]";
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