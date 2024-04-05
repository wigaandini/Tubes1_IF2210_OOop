#include "Building.hpp"

//class Building
Building::Building():Item(){

}

Building::Building(RecipeConfig recipe) : Item(recipe.name, recipe.code, recipe.price){
    this->material = recipe.materials;
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