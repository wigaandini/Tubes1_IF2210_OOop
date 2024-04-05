#include "ProductConfig.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
map<string, ProductConfig> ProductConfig::configs ;

ProductConfig::ProductConfig(){

}

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

void ProductConfig::loadConfigFromFile(string filename){
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int id, price, addedWeight;
        string name, code,origin;
        string typeStr;
        ProductType type;
        if (iss >> id >> code >> name >> typeStr >> origin >> addedWeight >> price)
        {
            if (typeStr == "PRODUCT_MATERIAL_PLANT")
                type = ProductType::PRODUCT_MATERIAL_PLANT;
            else if (typeStr == "PRODUCT_FRUIT_PLANT")
                type = ProductType::PRODUCT_FRUIT_PLANT;
            ProductConfig config(id,name,type,code,origin,addedWeight,price);
            configs[name] = config;
        }
    }
}

ProductConfig ProductConfig::getConfigFromName(const std::string &name)
{
    if (configs.find(name) != configs.end())
    {
        return configs[name];
    }
    else
    {
        throw std::runtime_error("Config not found for name: " + name);
    }
}
