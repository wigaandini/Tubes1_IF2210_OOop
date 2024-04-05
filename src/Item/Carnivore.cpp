#include "Carnivore.hpp"


Carnivore::Carnivore(string name, int weight) :Animal(weight, name){
    
}

Carnivore::Carnivore(string name) :Animal(0, name){
    
}

Carnivore& Carnivore::operator+(Product& product){
    if (product.getProductType() == ProductType::PRODUCT_ANIMAL_PLANT){
        this->setWeight(this->getWeight() + product.getAddedWeight());
    } else {
        throw "";
    }

}
