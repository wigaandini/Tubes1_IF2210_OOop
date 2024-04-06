#include "../Grid/Grid.hpp"
#include "../Item/Animal.hpp"
#include "../PColor/pcolor.h"

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
            cout << "    ";
            for (int j = 0; j < this->col; ++j) {
                cout << setw(5) << static_cast<char>('A' + j) << " ";
            }
            cout << "\n";
            cout << "     ";
            for (int j = 0; j < this->col; ++j) {
                cout << "+-----";
            }
            cout << "+\n";

            for (int i = 0; i < this->row; ++i) {
                cout << setw(2) << setfill(' ') << (i + 1) << "   |";
                for (int j = 0; j < this->col; ++j) {
                    string name = this->buffer[i][j].getCode();
                    cout << " " << setw(2) << setfill(' ');
                    if(this->buffer[i][j].getAnimalId() == -1){
                        cout << "   ";
                        cout << " |";
                    } else if (!this->buffer[i][j].checkReadyToHarvest()){
                        for (char ch : name) {
                            print_red(ch);
                        }
                        cout << "|";
                    } else if(this->buffer[i][j].checkReadyToHarvest()){
                        for (char ch : name) {
                            print_green(ch); 
                        }
                        cout << "|";
                    }
                }
                cout << endl; 
                cout << "     ";
                for (int j = 0; j < this->col; ++j) {
                    cout << "+-----";
                }
                cout << "+\n";
            }
            cout << endl;
            cout << endl;
            if(printInfo){
                for (int i = 0; i < this->row; i++)
                {
                    for (int j = 0; j < this->col; j++)
                    {
                        if(this->buffer[i][j].getAnimalId() != -1){
                            if (i < 10){
                                cout << "- " << char('A'+ j) << '0' << i + 1 << ": " << this->buffer[i][j].getName() << endl;
                            } else {
                                cout << "- " << char('A'+ j) << i + 1 << ": " << this->buffer[i][j].getName() << endl;
                            }
                        }
                    }
                    
                }
                
            }
        }

};