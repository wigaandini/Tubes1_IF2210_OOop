#include "Herbivore.hpp"

Herbivore::Herbivore(string name, int weight): Animal(weight,name){

}

Herbivore::Herbivore(string name): Animal(0,name){

}

Herbivore& Herbivore::operator+(Product& product){
    if (product.getProductType() == ProductType::PRODUCT_FRUIT_PLANT){
        this->setWeight(this->getWeight() + product.getAddedWeight());
    } else {
        throw "";
    }

    return *this;

}

Herbivore::~Herbivore(){
    
}

