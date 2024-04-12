#include "Ranch.hpp"
#include "../PColor/pcolor.h"
#include "../Game/Game.hpp"


Ranch::Ranch(int r, int c, Animal defaultValue) : Grid<Animal>(r, c, defaultValue) {}

Ranch::~Ranch() {}

Ranch::Ranch() : Grid<Animal>(Game::getMainConfig().ranchSize[0], Game::getMainConfig().ranchSize[1]){

}

void Ranch::displayStorage(bool printInfo) {
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
            string name = this->buffer[i][j]->getCode();
            cout << " " << setw(2) << setfill(' ');
            if (this->buffer[i][j]->getAnimalId() == -1) {
                cout << "   ";
                cout << " |";
            } else if (!this->buffer[i][j]->checkReadyToHarvest()) {
                for (char ch : name) {
                    print_red(ch);
                }
                cout << "|";
            } else if (this->buffer[i][j]->checkReadyToHarvest()) {
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
    if (printInfo) {
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                if (this->buffer[i][j]->getAnimalId() != -1) {
                    if (i < 10) {
                        cout << "- " << char('A' + j) << '0' << i + 1 << ": " << this->buffer[i][j]->getName() << endl;
                    } else {
                        cout << "- " << char('A' + j) << i + 1 << ": " << this->buffer[i][j]->getName() << endl;
                    }
                }
            }
        }
    }
}

bool Ranch::checkAnimalReadyToHarvest(){
    for (int i = 0; i < this->row; i++)
    {
       for (int j = 0; j < this->col; j++)
       {
        if(this->buffer[i][j]->checkReadyToHarvest()){
            return true;
        }
       }
    }
    return false;
}

map<string, int> Ranch::countAnimal(){
    map<string, int> animalCount;
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            if (this->buffer[i][j]->checkReadyToHarvest()) {
                string animalName = this->buffer[i][j]->getName();
                if (animalCount.find(animalName) == animalCount.end()) {
                    animalCount[animalName] = 1;
                } else {
                    animalCount[animalName]++;
                }
            }
        }
    }

    return animalCount;
}

int Ranch::countAnimalType(){
    map<string, int> animalCount = countAnimal();
    return animalCount.size();
}