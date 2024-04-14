#ifndef _LOADHANDLER_HPP_
#define _LOADHANDLER_HPP_

#include "../configClass/AnimalConfig.hpp"
#include "../configClass/PlantConfig.hpp"
#include "../configClass/ProductConfig.hpp"
#include "../configClass/MainConfig.hpp"
#include "../configClass/RecipeConfig.hpp"
#include <map>

class LoadHandler{
    public:
        void loadAnimalConfig(string filename);
        void loadPlantConfig(string filename);
        void loadProductConfig(string filename);
        void loadMainConfig(string filename);
        void loadRecipeConfig(string filename);
        void loadStateConfig(string filename);
        LoadHandler();
};      

#endif