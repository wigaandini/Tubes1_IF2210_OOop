#include "AnimalConfig.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

map<string, AnimalConfig> AnimalConfig::configs ;
AnimalConfig::AnimalConfig()
{
}

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

void AnimalConfig::loadConfigFromFile(string filename)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int id, price, weightToHarvest;
        string name, code;
        string typeStr;
        AnimalType type;
        if (iss >> id >> code >> name >> typeStr >> weightToHarvest >> price)
        {
            if (typeStr == "HERBIVORE")
                type = AnimalType::HERBIVORE;
            else if (typeStr == "CARNIVORE")
                type = AnimalType::CARNIVORE;
            else if (typeStr == "OMNIVORE")
                type = AnimalType::OMNIVORE;

            AnimalConfig config(id, name, type, price, code, weightToHarvest);
            configs[name] = config;
        }
    }
}

AnimalConfig AnimalConfig::getConfigFromName(const std::string &name)
{
    if (configs.find(name) != configs.end())
    {
        return configs[name];
    }
    else
    {
        throw std::runtime_error("Config not found for name: " + name);
    }
}
