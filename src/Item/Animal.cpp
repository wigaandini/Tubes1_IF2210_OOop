#include "Animal.hpp"
// class Animal
Animal::Animal() : Item(){
    this->animalId = -1;
    this->weight = 0;
    this->weighToHarvest = 0;
}
      
Animal::Animal(string name, float weight) : Item(AnimalConfig::configs[name].name, AnimalConfig::configs[name].code, AnimalConfig::configs[name].price){
    this->type = AnimalConfig::configs[name].type;
    this->animalId = AnimalConfig::configs[name].id;
    this->weight = weight;
    this->weighToHarvest = AnimalConfig::configs[name].weightToHarvest;
}

void Animal::setAnimalId(int animalId){
    this->animalId = animalId;
}

void Animal::setWeight(float weight){
    this->weight = weight;
}

void Animal::setWeightToHarvest(float weightToHarvest){
    this->weighToHarvest = weighToHarvest;
}

int Animal::getAnimalId() const{
    return this->animalId;
}

float Animal::getWeight() const{
    return this->weight;
}

float Animal::getWeightToHarvest() const{
    return this->weighToHarvest;
}

Animal& Animal::operator+(Product product){
    this->weight += product.getAddedWeight();
    return *this;
}

void Animal::eat(Product product){
    this->
}