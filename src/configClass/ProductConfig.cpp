#include "ProductConfig.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;


ProductConfig::ProductConfig(int id, string name, ProductType type, string code,string origin,int addedWeight,int price){
    this->id = id;
    this->name = name;
    this->type = type;
    this->code = code;
    this->origin = origin;
    this->addedWeight = addedWeight;
    this->price = price;
}

ProductConfig::~ProductConfig(){

}


