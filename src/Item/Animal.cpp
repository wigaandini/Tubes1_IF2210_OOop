#include "Animal.hpp"
// class Animal
Animal::Animal() : Item(){
    this->animalId = -1;
    this->weight = 0;
    this->weighToHarvest = 0;
}


Animal::Animal(int weight, AnimalConfig& animalConfig, vector<Product>& result):Item(), weight(weight), animalId(animalConfig.id), weighToHarvest(animalConfig.weightToHarvest), result(result) {
    
}

Animal::Animal(AnimalConfig& animalConfig, vector<Product>& result):Item(), weight(0), animalId(animalConfig.id), weighToHarvest(animalConfig.weightToHarvest), result(result) {
    
}

void Animal::setAnimalId(int animalId){
    this->animalId = animalId;
}

void Animal::setWeight(int weight){
    this->weight = weight;
}

void Animal::setWeightToHarvest(int weightToHarvest){
    this->weighToHarvest = weighToHarvest;
}

int Animal::getAnimalId() const{
    return this->animalId;
}

int Animal::getWeight() const{
    return this->weight;
}

int Animal::getWeightToHarvest() const{
    return this->weighToHarvest;
}



vector<Product>& Animal::collect(){
    return this->result;
}
