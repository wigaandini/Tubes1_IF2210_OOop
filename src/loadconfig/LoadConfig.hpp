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
        void loadAnimalConfig(string filename);
        void loadPlantConfig(string filename);
        void loadProductConfig(string filename);
        void loadMainConfig(string filename);
        void loadRecipeConfig(string filename);
        LoadConfig();
};      

#endif