#include "Animal.hpp"
// class Animal
Animal::Animal() : Item(){
    this->animalId = -1;
    this->weight = 0;
    this->weighToHarvest = 0;
}
      
// Animal::Animal(string name, float weight) : Item(AnimalConfig::configs[name].name, AnimalConfig::configs[name].code, AnimalConfig::configs[name].price){
//     this->type = AnimalConfig::configs[name].type;
//     this->animalId = AnimalConfig::configs[name].id;
//     this->weight = weight;
//     this->weighToHarvest = AnimalConfig::configs[name].weightToHarvest;
// }

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
