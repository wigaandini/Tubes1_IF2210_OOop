#include "Building.hpp"
#include "../Game/Game.hpp"

//class Building
Building::Building():Item(){

}

Building::Building(string name) : Item(Game::getRecipe()[name].name, Game::getRecipe()[name].code, Game::getRecipe()[name].price){
    this->material = Game::getRecipe()[name].materials;
}

Building::~Building(){
    
}

int Building::getQuantityPerMaterial(string materialName) const{
    try {
        return material.at(materialName);
    } catch (const std::out_of_range& e) {
        
        
        return 0;
    }
}

map<string, int> Building::getBuildingMaterial() const{
    return this->material;
}