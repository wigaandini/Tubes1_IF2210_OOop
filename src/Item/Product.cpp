#include "Product.hpp"
#include "../Game/Game.hpp"

// class Product
Product::Product() : Item(){
    this->productId = -1;
    this->origin = "";
    this->addedWeight = 0;
}

Product::Product(string name) : Item(Game::getProductConfig()[name].name, Game::getProductConfig()[name].code, Game::getProductConfig()[name].price){
    this->type = Game::getProductConfig()[name].type;
    this->productId = Game::getProductConfig()[name].id;
    this->origin = Game::getProductConfig()[name].origin;
    this->addedWeight = Game::getProductConfig()[name].addedWeight;
}



Product::~Product(){
    
}

void Product::setProductType(ProductType type){
    this->type = type;
}

void Product::setProductId(int productId){
    this->productId = productId;
}

void Product::setOrigin(string origin){
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

