#include "ProductConfig.hpp"

ProductConfig::ProductConfig(int id, string name, ProductType type, string code, string origin, int addedWeight, int price)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->code = code;
    this->origin = origin;
    this->addedWeight = addedWeight;
    this->price = price;
}

ProductConfig::~ProductConfig()
{
}

ProductConfig::ProductConfig()
{
    this->id = -1;
    this->name = "";
    this->type = ProductType::PRODUCT_ANIMAL;
    this->code = "";
    this->origin = "";
    this->addedWeight = 0;
    this->price = 0;
}
