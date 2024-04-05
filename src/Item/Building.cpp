#include "Building.hpp"

//class Building
Building::Building():Item(){

}

Building::Building(string name):Item(RecipeConfig::recipes[name].name,RecipeConfig::recipes[name].code,RecipeConfig::recipes[name].price){
    this->material = RecipeConfig::recipes[name].materials;
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