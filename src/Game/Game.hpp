#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <map>
#include "../configClass/AnimalConfig.hpp"
#include "../configClass/PlantConfig.hpp"
#include "../configClass/MainConfig.hpp"
#include "../configClass/RecipeConfig.hpp"
#include "../configClass/ProductConfig.hpp"
#include "../loadconfig/LoadConfig.hpp"
#include "../Store/Store.hpp"
using namespace std;

class Game {
    private:
        map<string, AnimalConfig> animalConfig;
        map<string, PlantConfig> plantConfig;
        map<string, RecipeConfig> recipe;
        map<string, ProductConfig> productConfig;
        MainConfig mainConfig;
        LoadConfig configHandler;
        Store store;

    public:
        map<string, AnimalConfig>& getAnimalConfig();
};

#endif
