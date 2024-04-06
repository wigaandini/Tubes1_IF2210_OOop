#include "PlantConfig.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

PlantConfig::PlantConfig(int id, string name, PlantType type, string code, int durationToHarvest, int price)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->code = code;
    this->durationToHarvest = durationToHarvest;
    this->price = price;
}

PlantConfig::~PlantConfig()
{
}

PlantConfig::PlantConfig()
{
    this->id = -1;
    this->name = "";
    this->type = PlantType::FRUIT_PLANT;
    this->code = "";
    this->durationToHarvest = 0;
    this->price = 0;
}
