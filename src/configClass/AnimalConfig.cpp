#include "AnimalConfig.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

AnimalConfig::AnimalConfig(int id, string name, AnimalType type, int price, string code, int weightToHarvest)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->price = price;
    this->code = code;
    this->weightToHarvest = weightToHarvest;
}

AnimalConfig::~AnimalConfig()
{
}


