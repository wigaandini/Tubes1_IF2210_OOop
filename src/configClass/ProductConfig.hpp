#ifndef _PRODUCTCONFIG_HPP_
#define _PRODUCTCONFIG_HPP_

#include <string>
using namespace std;

enum class ProductType{
    PRODUCT_MATERIAL_PLANT,
    PRODUCT_FRUIT_PLANT,
    PRODUCT_ANIMAL_PLANT
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
};






#endif