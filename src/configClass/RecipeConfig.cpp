#include "RecipeConfig.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

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

