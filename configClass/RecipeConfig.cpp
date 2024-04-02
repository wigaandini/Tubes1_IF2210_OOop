#include "RecipeConfig.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

map<string, RecipeConfig> RecipeConfig::recipes;

RecipeConfig::RecipeConfig(){

}

RecipeConfig::RecipeConfig(int id, string name, string code, int price, map<string, int> materials){
    this->id = id;
    this->name = name;
    this->code = code;
    this->price = price;
    this->materials = materials;
}

RecipeConfig::~RecipeConfig(){

}

void RecipeConfig::loadConfigFromFile(const string& filename){
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int id, price;
        string code, name;
        map<string, int> materials;

        iss >> id >> code >> name >> price;

        string materialName;
        int quantity;
        // Loop through the rest of the line to read materials and quantities.
        while (iss >> materialName >> quantity) {
            materials[materialName] = quantity;
        }

        // Create a new RecipeConfig object and add it to the map.
        recipes[code] = RecipeConfig(id, name, code, price, materials);
    }
}

RecipeConfig RecipeConfig::getConfigFromName(const string& name){
    if (recipes.find(name) != recipes.end()){
        return recipes[name];
    }else{
        throw std::runtime_error("Config not found for name: " + name);
    }
}