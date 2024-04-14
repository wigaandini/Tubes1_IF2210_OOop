#include "Animal.hpp"
#include "../Game/Game.hpp"

map<string, vector<string>> Animal::harvestResult = {
    {"COW", {"COW_MEAT"}},
    {"SHEEP", {"SHEEP_MEAT"}},
    {"HORSE", {"HORSE_MEAT"}},
    {"RABBIT", {"RABBIT_MEAT"}},
    {"SNAKE", {"SNAKE_MEAT"}},
    {"CHICKEN", {"CHICKEN_MEAT", "CHICKEN_EGG"}},
    {"DUCK", {"DUCK_MEAT", "DUCK_EGG"}},
};


// class Animal
Animal::Animal() : Item()
{
    this->animalId = -1;
    this->weight = 0;
    this->weighToHarvest = 0;
}

Animal::Animal(int weight, string name) : Item(Game::getAnimalConfig()[name].name, Game::getAnimalConfig()[name].code, Game::getAnimalConfig()[name].price), animalId(Game::getAnimalConfig()[name].id), weight(weight), weighToHarvest(Game::getAnimalConfig()[name].weightToHarvest)
{
}

Animal::~Animal(){

}

void Animal::setAnimalId(int animalId)
{
    this->animalId = animalId;
}

void Animal::setWeight(int weight)
{
    this->weight = weight;
}

void Animal::setWeightToHarvest(int weightToHarvest)
{
    this->weighToHarvest = weightToHarvest;
}

int Animal::getAnimalId() const
{
    return this->animalId;
}

int Animal::getWeight() const
{
    return this->weight;
}

int Animal::getWeightToHarvest() const
{
    return this->weighToHarvest;
}

vector<shared_ptr<Product>> Animal::collect(){
    // vector<shared_ptr<Product>> tempP;
    // for(unsigned int i = 0; i < harvestResult[this->name].size(); i++){
    //     tempP.push_back(make_shared<Product>(harvestResult[this->name][i]));
        
    // }

    return this->harvester.collect(this->harvestResult, this->name);
}

bool Animal::checkReadyToHarvest()
{
    if (this->weight >= this->weighToHarvest)
    {
        return true;
    }
    return false;
}


map<string, vector<string>>& Animal::getHarvestResult(){
    return harvestResult;
}

void Animal::eat(const shared_ptr<Product>& food){
    this->setWeight(this->getWeight() + food->getAddedWeight());
}

