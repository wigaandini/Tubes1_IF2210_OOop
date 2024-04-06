#include "LoadConfig.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "../Game/Game.hpp"
using namespace std;

void LoadConfig::loadAnimalConfig(string filename){
    map<string,AnimalConfig> configs;
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

    Game::setAnimalConfig(configs);
}

void LoadConfig::loadPlantConfig(string filename){
    map<string,PlantConfig> configs;
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

    Game::setPlantConfig(configs);
}
        
void loadProductConfig(string filename){
    map<string,ProductConfig> configs;
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int id, price, addedWeight;
        string name, code,origin;
        string typeStr;
        ProductType type;
        if (iss >> id >> code >> name >> typeStr >> origin >> addedWeight >> price)
        {
            if (typeStr == "PRODUCT_MATERIAL_PLANT")
                type = ProductType::PRODUCT_MATERIAL_PLANT;
            else if (typeStr == "PRODUCT_FRUIT_PLANT")
                type = ProductType::PRODUCT_FRUIT_PLANT;
            else if (typeStr == "PRODUCT_ANIMAL")
                type = ProductType::PRODUCT_ANIMAL;
            ProductConfig config(id,name,type,code,origin,addedWeight,price);
            configs[name] = config;
        }
    }

    Game::setProductConfig(configs);
}
        
void loadMainConfig(string filename){
    MainConfig config;
    ifstream file(filename);
    int guldenForWin,weightPlayerToWin;
    int inventorySize[2];
    int farmSize[2];
    int ranchSize[2];

    file >> guldenForWin >> weightPlayerToWin;
    file >> inventorySize[0] >> inventorySize[1];
    file >> farmSize[0] >> farmSize[1];
    file >> ranchSize[0] >> ranchSize[1];

    
    config = MainConfig(guldenForWin, weightPlayerToWin, inventorySize, farmSize, ranchSize);
    Game::setMainConfig(config);  
}
        
void loadRecipeConfig(string filename){
    map<string,RecipeConfig> recipes;
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

    Game::setRecipe(recipes);
}

LoadConfig::LoadConfig(){

}
