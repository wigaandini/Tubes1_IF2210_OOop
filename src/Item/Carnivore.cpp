#include "Carnivore.hpp"

Carnivore& Carnivore::operator+(Product& product){
    if (product.getProductType() == ProductType::PRODUCT_ANIMAL_PLANT){
        this->setWeight(this->getWeight() + product.getAddedWeight());
    } else {
        throw "";
    }

}
