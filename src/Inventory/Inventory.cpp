#include "Inventory.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Constructor
Inventory::Inventory(int r, int c, Item defaultValue) : Grid<Item>(r, c, defaultValue) {}

// Destructor
Inventory::~Inventory() {}

// Member function displayStorage
void Inventory::displayStorage(bool printInfo) {
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

bool Inventory::checkInventoryEdible(){
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            if(Game::getProductConfig()[this->buffer[i][j].getName()].type != ProductType::PRODUCT_MATERIAL_PLANT){
                return true;
            }
        }
    }
    return false;
}