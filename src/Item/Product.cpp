#include "Product.hpp"

// class Product
Product::Product() : Item(){
    this->productId = -1;
    this->origin = "";
    this->addedWeight = 0;
}

Product::Product(string name) : Item(ProductConfig::configs[name].name, ProductConfig::configs[name].code, ProductConfig::configs[name].price){
    this->type = ProductConfig::configs[name].type;
    this->productId = ProductConfig::configs[name].id;
    this->origin = ProductConfig::configs[name].origin;
    this->addedWeight = ProductConfig::configs[name].addedWeight;
}

void Product::setProductType(ProductType type){
    this->type = type;
}

void Product::setProductId(int productId){
    this->productId = productId;
}

void Product::setOrigin(float origin){
    this->origin = origin;
}

void Product::setAddedWeight(float addedWeight){
    this->addedWeight = addedWeight;
}

ProductType Product::getProductType() const{
    return this->type;
}

int Product::getProductId() const{
    return this->productId;
}

string Product::getOrigin() const{
    return this->origin;    
}

float Product::getAddedWeight() const{
    return this->addedWeight;
}

