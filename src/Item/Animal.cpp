#include "Animal.hpp"
#include "../Game/Game.hpp"
// class Animal
Animal::Animal() : Item(){
    this->animalId = -1;
    this->weight = 0;
    this->weighToHarvest = 0;
}


Animal::Animal(int weight, string name):Item(Game::getAnimalConfig()[name].name,Game::getAnimalConfig()[name].code,Game::getAnimalConfig()[name].price), weight(weight), animalId(Game::getAnimalConfig()[name].id), weighToHarvest(Game::getAnimalConfig()[name].weightToHarvest){
    
}



void Animal::setAnimalId(int animalId){
    this->animalId = animalId;
}

void Animal::setWeight(int weight){
    this->weight = weight;
}

void Animal::setWeightToHarvest(int weightToHarvest){
    this->weighToHarvest = weightToHarvest;
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

bool Animal::checkReadyToHarvest(){
    if (this->weight >= this->weighToHarvest){
        return true;
    }
    return false;
}