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

bool Inventory::checkInventoryAnimal(){
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            if(Game::getAnimalConfig()[this->buffer[i][j].getName()].type == AnimalType::HERBIVORE || Game::getAnimalConfig()[this->buffer[i][j].getName()].type == AnimalType::CARNIVORE || Game::getAnimalConfig()[this->buffer[i][j].getName()].type == AnimalType::OMNIVORE){
                return true;
            }
        }
    }
    return false;
}

bool Inventory::checkInventoryPlant(){
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            if(Game::getPlantConfig()[this->buffer[i][j].getName()].type == PlantType::MATERIAL_PLANT || Game::getPlantConfig()[this->buffer[i][j].getName()].type == PlantType::FRUIT_PLANT){
                return true;
            }
        }
    }
    return false;
}

void Inventory::putRandom(const Item& item){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col ; j++){
            if(this->buffer[i][j].getItemId() == -1){
                this->buffer[i][j] = item;
            }
        }
    }
}

bool Inventory::checkInventoryFruit(){
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            if(Game::getProductConfig()[this->buffer[i][j].getName()].type == ProductType::PRODUCT_FRUIT_PLANT ){
                return true;
            }
        }
    }
    return false;
}


bool Inventory::checkInventoryMeat(){
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            if(Game::getProductConfig()[this->buffer[i][j].getName()].type == ProductType::PRODUCT_ANIMAL){
                return true;
            }
        }
    }
    return false;
}