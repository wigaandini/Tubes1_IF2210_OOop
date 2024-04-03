#ifndef __RECIPECONFIG_HPP_
#define __RECIPECONFIG_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class RecipeConfig {
    public :
        static map<string, RecipeConfig> recipes;
        int id;
        string name;
        string code;
        int price;
        map<string, int> materials;

        RecipeConfig();
        RecipeConfig(int id, string name, string code, int price, map<string, int> materials);
        ~RecipeConfig();
        static void loadConfigFromFile(const string& filename);
        static RecipeConfig getConfigFromName(const string& name);
};      

#endif