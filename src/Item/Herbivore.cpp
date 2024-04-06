#include "Herbivore.hpp"

Herbivore::Herbivore(string name, int weight): Animal(weight,name){

}

Herbivore::Herbivore(string name): Animal(0,name){

}

void Herbivore::eat(Product& product){
    if (product.getProductType() == ProductType::PRODUCT_FRUIT_PLANT){
        Animal::eat(product);
    } else {
        throw "";
    }


}

Herbivore::~Herbivore(){

}

