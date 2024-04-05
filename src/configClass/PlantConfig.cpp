#include "PlantConfig.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

map<string, PlantConfig> PlantConfig::configs;

PlantConfig::PlantConfig(){
}

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

void PlantConfig::loadConfigFromFile(const string& filename){
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int id, durationToHarvest, price;
        string name, code;
        string typeStr;
        PlantType type;
        if (iss >> id >> code >> name >> typeStr >> durationToHarvest >> price)
        {
            if (typeStr == "MATERIAL_PLANT")
                type = PlantType::MATERIAL_PLANT;
            else if (typeStr == "FRUIT_PLANT")
                type = PlantType::FRUIT_PLANT;

            PlantConfig config(id, name, type, code, durationToHarvest, price);
            configs[name] = config;
        }
    }
}

PlantConfig PlantConfig::getConfigFromName(const string& name){
    if (configs.find(name) != configs.end()){
        return configs[name];
    }else{
        throw std::runtime_error("Config not found for name: " + name);
    }
}