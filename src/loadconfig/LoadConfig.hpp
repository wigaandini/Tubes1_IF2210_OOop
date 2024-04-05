#ifndef _LOADCONFIG_HPP_
#define _LOADCONFIG_HPP_

#include "../configClass/AnimalConfig.hpp"
#include "../configClass/PlantConfig.hpp"
#include "../configClass/ProductConfig.hpp"
#include "../configClass/MainConfig.hpp"
#include "../configClass/RecipeConfig.hpp"
#include <map>

class LoadConfig{
    public:
        void loadAnimalConfig(map<string,AnimalConfig>& configs,string filename);
        void loadPlantConfig(map<string,PlantConfig>& configs,string filename);
        void loadProductConfig(map<string,ProductConfig>& configs,string filename);
        void loadMainConfig(MainConfig& config,string filename);
        void loadRecipeConfig(map<string,RecipeConfig>& recipes,string filename);
};      

#endif