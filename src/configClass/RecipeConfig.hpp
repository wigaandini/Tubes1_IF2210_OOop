#ifndef __RECIPECONFIG_HPP_
#define __RECIPECONFIG_HPP_

#include <string>
#include <map>

using namespace std;

class RecipeConfig {
    public :
        int id;
        string name;
        string code;
        int price;
        map<string, int> materials;
};      

#endif