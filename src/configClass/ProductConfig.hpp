#ifndef _PRODUCTCONFIG_HPP_
#define _PRODUCTCONFIG_HPP_

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

enum class ProductType{
    PRODUCT_MATERIAL_PLANT,
    PRODUCT_FRUIT_PLANT,
    PRODUCT_ANIMAL
};

class ProductConfig{
public:
    int id;
    string name;
    ProductType type;
    string code;
    string origin;
    int addedWeight;
    int price;

    ProductConfig(int id, string name, ProductType type, string code,string origin,int addedWeight,int price);
    ~ProductConfig();
    ProductConfig();
};






#endif