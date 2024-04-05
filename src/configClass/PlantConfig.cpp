#include "PlantConfig.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

PlantConfig::PlantConfig(int id, string name, PlantType type, string code, int durationToHarvest, int price){
    this->id = id;
    this->name = name;
    this->type = type;
    this->code = code;
    this->durationToHarvest = durationToHarvest;
    this->price = price;
}

PlantConfig::~PlantConfig(){

}

