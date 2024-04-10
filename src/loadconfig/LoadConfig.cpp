#include "LoadConfig.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>

#include "../Game/Game.hpp"

#include "../Breeder/Breeder.hpp"
#include "../Farmer/Farmer.hpp"
#include "../Mayor/Mayor.hpp"
#include "../Item/Carnivore.hpp"
#include "../Item/Omnivore.hpp"
#include "../Item/Herbivore.hpp"
#include "../Item/Plant.hpp"
#include "../Item/Animal.hpp"
#include "../Item/Product.hpp"
#include "../Item/Building.hpp"
using namespace std;

void LoadConfig::loadAnimalConfig(string filename)
{
    map<string, AnimalConfig> configs;
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int id, price, weightToHarvest;
        string name, code;
        string typeStr;
        AnimalType type = AnimalType::CARNIVORE;
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

void LoadConfig::loadPlantConfig(string filename)
{
    map<string, PlantConfig> configs;
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int id, durationToHarvest, price;
        string name, code;
        string typeStr;
        PlantType type = PlantType::MATERIAL_PLANT;
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

void LoadConfig::loadProductConfig(string filename)
{
    map<string, ProductConfig> configs;
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int id, price, addedWeight;
        string name, code, origin;
        string typeStr;
        ProductType type = ProductType::PRODUCT_ANIMAL;
        if (iss >> id >> code >> name >> typeStr >> origin >> addedWeight >> price)
        {
            if (typeStr == "PRODUCT_MATERIAL_PLANT")
                type = ProductType::PRODUCT_MATERIAL_PLANT;
            else if (typeStr == "PRODUCT_FRUIT_PLANT")
                type = ProductType::PRODUCT_FRUIT_PLANT;
            else if (typeStr == "PRODUCT_ANIMAL")
                type = ProductType::PRODUCT_ANIMAL;
            ProductConfig config(id, name, type, code, origin, addedWeight, price);
            configs[name] = config;
        }
    }

    Game::setProductConfig(configs);
}

void LoadConfig::loadMainConfig(string filename)
{
    MainConfig config;
    ifstream file(filename);
    int guldenForWin, weightPlayerToWin;
    int inventorySize[2];
    int farmSize[2];
    int ranchSize[2];

    file >> guldenForWin >> weightPlayerToWin;
    file >> inventorySize[0] >> inventorySize[1];
    file >> farmSize[0] >> farmSize[1];
    file >> ranchSize[0] >> ranchSize[1];

    // cout << ranchSize[0] << ranchSize[1] << endl;
    config = MainConfig(guldenForWin, weightPlayerToWin, inventorySize, farmSize, ranchSize);
    Game::getMainConfig().farmSize[0] = farmSize[0];
    Game::getMainConfig().farmSize[1] = farmSize[1];

    Game::getMainConfig().ranchSize[0] = ranchSize[0];
    Game::getMainConfig().ranchSize[1] = ranchSize[1];

    Game::getMainConfig().inventorySize[0] = inventorySize[0];
    Game::getMainConfig().inventorySize[1] = inventorySize[1];

    Game::getMainConfig().guldenForWin = guldenForWin;
    Game::getMainConfig().weightPlayerToWin = weightPlayerToWin;
}

void LoadConfig::loadRecipeConfig(string filename)
{
    map<string, RecipeConfig> recipes;
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
        while (iss >> materialName >> quantity)
        {
            materials[materialName] = quantity;
        }

        // Create a new RecipeConfig object and add it to the map.
        recipes[name] = RecipeConfig(id, name, code, price, materials);
    }

    Game::setRecipe(recipes);
}

LoadConfig::LoadConfig()
{
}

void LoadConfig::loadStateConfig(string filename)
{
    ifstream file(filename);

    int numPlayers;
    file >> numPlayers;
    file.ignore();

    for (int i = 0; i < numPlayers; ++i)
    {
        string playerName, role;
        int weight, gulden;
        int totalItem;
        file >> playerName >> role >> weight >> gulden;
        file.ignore();

        if (role == "Walikota")
        {
            auto player = make_shared<Mayor>(playerName, weight, gulden);
            file >> totalItem;
            string itemName;
            for (int j = 0; j < totalItem; j++)
            {
                file >> itemName;

                if (Game::getAnimalConfig().find(itemName) != Game::getAnimalConfig().end())
                {
                    if (Game::getAnimalConfig()[itemName].type == AnimalType::CARNIVORE)
                    {
                        player->getInventory().putRandom(make_shared<Carnivore>(itemName));
                    }
                    else if (Game::getAnimalConfig()[itemName].type == AnimalType::HERBIVORE)
                    {
                        player->getInventory().putRandom(make_shared<Herbivore>(itemName));
                    }
                    else if (Game::getAnimalConfig()[itemName].type == AnimalType::OMNIVORE)
                    {
                        player->getInventory().putRandom(make_shared<Omnivore>(itemName));
                    }
                }
                else if (Game::getPlantConfig().find(itemName) != Game::getPlantConfig().end())
                {
                    player->getInventory().putRandom(make_shared<Plant>(itemName));
                }
                else if (Game::getProductConfig().find(itemName) != Game::getProductConfig().end())
                {
                    player->getInventory().putRandom(make_shared<Product>(itemName));
                }
                else if (Game::getRecipe().find(itemName) != Game::getRecipe().end())
                {
                    player->getInventory().putRandom(make_shared<Building>(itemName));
                }
            }

            Game::getPlayers().push_back(player);
        }
        else if (role == "Peternak")
        {
            auto player = make_shared<Breeder>(playerName, weight, gulden);
            file >> totalItem;
            string itemName;
            for (int j = 0; j < totalItem; j++)
            {
                file >> itemName;

                if (Game::getAnimalConfig().find(itemName) != Game::getAnimalConfig().end())
                {
                    if (Game::getAnimalConfig()[itemName].type == AnimalType::CARNIVORE)
                    {
                        player->getInventory().putRandom(make_shared<Carnivore>(itemName));
                    }
                    else if (Game::getAnimalConfig()[itemName].type == AnimalType::HERBIVORE)
                    {
                        player->getInventory().putRandom(make_shared<Herbivore>(itemName));
                    }
                    else if (Game::getAnimalConfig()[itemName].type == AnimalType::OMNIVORE)
                    {
                        player->getInventory().putRandom(make_shared<Omnivore>(itemName));
                    }
                }
                else if (Game::getPlantConfig().find(itemName) != Game::getPlantConfig().end())
                {
                    player->getInventory().putRandom(make_shared<Plant>(itemName));
                }
                else if (Game::getProductConfig().find(itemName) != Game::getProductConfig().end())
                {
                    player->getInventory().putRandom(make_shared<Product>(itemName));
                }
                else if (Game::getRecipe().find(itemName) != Game::getRecipe().end())
                {
                    player->getInventory().putRandom(make_shared<Building>(itemName));
                }
            }

            file >> totalItem;
            // cout << totalItem << endl;
            string slot;
            int berat;
            for (int j = 0; j < totalItem; j++)
            {
                file >> slot >> itemName >> berat;

                if (Game::getAnimalConfig()[itemName].type == AnimalType::CARNIVORE)
                {
                    player->getRanch().put(slot, make_shared<Carnivore>(itemName, berat));
                }
                else if (Game::getAnimalConfig()[itemName].type == AnimalType::HERBIVORE)
                {

                    player->getRanch().put(slot, make_shared<Herbivore>(itemName, berat));
                }
                else if (Game::getAnimalConfig()[itemName].type == AnimalType::OMNIVORE)
                {

                    player->getRanch().put(slot, make_shared<Omnivore>(itemName, berat));
                }
            }

            Game::getPlayers().push_back(player);
        }
        else if (role == "Petani")
        {
            auto player = make_shared<Farmer>(playerName, weight, gulden);
            file >> totalItem;
            string itemName;
            for (int j = 0; j < totalItem; j++)
            {
                file >> itemName;

                if (Game::getAnimalConfig().find(itemName) != Game::getAnimalConfig().end())
                {
                    if (Game::getAnimalConfig()[itemName].type == AnimalType::CARNIVORE)
                    {
                        player->getInventory().putRandom(make_shared<Carnivore>(itemName));
                    }
                    else if (Game::getAnimalConfig()[itemName].type == AnimalType::HERBIVORE)
                    {
                        player->getInventory().putRandom(make_shared<Herbivore>(itemName));
                    }
                    else if (Game::getAnimalConfig()[itemName].type == AnimalType::OMNIVORE)
                    {
                        player->getInventory().putRandom(make_shared<Omnivore>(itemName));
                    }
                }
                else if (Game::getPlantConfig().find(itemName) != Game::getPlantConfig().end())
                {
                    player->getInventory().putRandom(make_shared<Plant>(itemName));
                }
                else if (Game::getProductConfig().find(itemName) != Game::getProductConfig().end())
                {
                    player->getInventory().putRandom(make_shared<Product>(itemName));
                }
                else if (Game::getRecipe().find(itemName) != Game::getRecipe().end())
                {
                    player->getInventory().putRandom(make_shared<Building>(itemName));
                }
            }

            file >> totalItem;
            string slot;
            int umur;
            for (int j = 0; j < totalItem; j++)
            {
                file >> slot >> itemName >> umur;

                player->getFarm().put(slot, make_shared<Plant>(umur, itemName));
            }

            Game::getPlayers().push_back(player);
        }
    }

    sort(Game::getPlayers().begin(), Game::getPlayers().end(), [](const auto &a, const auto &b)
         { return a->getName() < b->getName(); });

    int storeAmount;
    string storeItemName;
    int amount;
    file >> storeAmount;

    for (int j = 0; j < storeAmount; j++)
    {
        file >> storeItemName >> amount;

        for (int k = 0; k < amount; k++)
        {

            if (Game::getProductConfig().find(storeItemName) != Game::getProductConfig().end())
            {
                Game::getStore().addItem(make_shared<Product>(storeItemName));
            }
            else if (Game::getRecipe().find(storeItemName) != Game::getRecipe().end())
            {
                Game::getStore().addItem(make_shared<Building>(storeItemName));
            }
        }
    }
}
