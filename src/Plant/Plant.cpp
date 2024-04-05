#include "Plant.hpp"
// class Plant
Plant::Plant() : Item(){
    this->plantId = -1;
    this->durationToHarvest = 0;
    this->age = 0;
}

Plant::Plant(string name, int age) : Item(PlantConfig::configs[name].name, PlantConfig::configs[name].code, PlantConfig::configs[name].price){
    this->type = PlantConfig::configs[name].type;
    this->plantId = PlantConfig::configs[name].id;
    this->durationToHarvest = PlantConfig::configs[name].durationToHarvest;
    this->age = age;
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