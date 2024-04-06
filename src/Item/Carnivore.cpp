#include "Carnivore.hpp"


Carnivore::Carnivore(string name, int weight) :Animal(weight, name){

}

Carnivore::Carnivore(string name) :Animal(0, name){
    
}

void Carnivore::eat(Product& product){
    if (product.getProductType() == ProductType::PRODUCT_ANIMAL){
        Animal::eat(product);
    } else {
        throw "";
    }

    return *this;
}

Carnivore::~Carnivore(){

}
