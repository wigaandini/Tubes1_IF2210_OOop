#include "Plant.hpp"
// class Plant
Plant::Plant() : Item(){
    this->plantId = -1;
    this->durationToHarvest = 0;
    this->age = 0;
}

Plant::Plant(int age, PlantConfig& plant, vector<Product>& result) : Item(name, plant.code, plant.price){
    this->type = plant.type;
    this->plantId = plant.id;
    this->durationToHarvest = plant.durationToHarvest;
    this->age = age;
    this->result = result;
}

Plant::Plant(PlantConfig& plant, vector<Product>& result) : Item(name, plant.code, plant.price){
    this->type = plant.type;
    this->plantId = plant.id;
    this->durationToHarvest = plant.durationToHarvest;
    this->age = 0;
    this->result = result;
}
void Plant::setPlantType(PlantType type){
    this->type = type;
}

void Plant::setPlantId(int plantId){
    this->plantId = plantId;
}

void Plant::setDurationToHarvest(int durationToHarvest){
    this->durationToHarvest = durationToHarvest;
}

void Plant::setAge(int age){
    this->age = age;
}

PlantType Plant::getPlantType() const{
    return this->type;
}

int Plant::getPlantId() const{
    return this->plantId;
}

int Plant::getDurationToHarvest() const{
    return this->durationToHarvest;
}

int Plant::getAge() const{
    return this->age;
}

Plant& Plant::operator++(){
    ++this->age;
    return *this;
}

Plant Plant::operator++(int ){
    Plant temp = *this;
    ++this->age;
    return temp;
}

vector<Product> Plant::collect(){
    return this->result;
}

bool Plant::checkReadyToHarvest(){
    if (this->age >= this->durationToHarvest){
        return true;
    }
    return false;
}