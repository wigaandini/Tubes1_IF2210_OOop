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
        static map<string, AnimalConfig> animalConfig;
        static map<string, PlantConfig> plantConfig;
        static map<string, RecipeConfig> recipe;
        static map<string, ProductConfig> productConfig;
        static MainConfig mainConfig;
        LoadConfig configHandler;
        static Store store;

    public:
        static map<string, AnimalConfig>& getAnimalConfig();
        static map<string, PlantConfig>& getPlantConfig();
        static map<string, RecipeConfig>& getRecipe();
        static map<string, ProductConfig>& getProductConfig();
        static MainConfig& getMainConfig();
        static Store& getStore();
        static void setAnimalConfig(const map<string, AnimalConfig>&);
        static void setPlantConfig(const map<string, PlantConfig>&);
        static void setRecipe(const map<string, RecipeConfig>&);
        static void setProductConfig(const map<string, ProductConfig>&);
        static void setMainConfig(const MainConfig&);
        LoadConfig& getLoadConfig();
        void mainLoop();
        void handleSave();
        void handleLoad();
        void handleNext();
};

#endif
