#include "Farm.hpp"
#include "../PColor/pcolor.h"


Farm::Farm(int r, int c, Plant defaultValue) : Grid<Plant>(r, c, defaultValue) {}

Farm::~Farm() {}

void Farm::displayStorage(bool printInfo) {
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
            if(this->buffer[i][j].getPlantId() == -1){
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
         for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                if(this->buffer[i][j].getPlantId() != -1){
                    cout << "- " << this->buffer[i][j].getCode() << ": " << this->buffer[i][j].getName() << endl;
                }
            }
        }
    }
}

bool Farm::checkPlantReadyToHarvest(){
    for (int i = 0; i < this->row; i++)
    {
       for (int j = 0; j < this->col; j++)
       {
        if(this->buffer[i][j].checkReadyToHarvest()){
            return true;
        }
       }
    }
    return false;
}

map<string, int> Farm::countPlant(){
    map<string, int> plantCount;
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            if (this->buffer[i][j].checkReadyToHarvest()) {
                string plantName = this->buffer[i][j].getCode();
                if (plantCount.find(plantName) == plantCount.end()) {
                    plantCount[plantName] = 1;
                } else {
                    plantCount[plantName]++;
                }
            }
        }
    }
    return plantCount;
}