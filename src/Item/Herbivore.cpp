#include "Herbivore.hpp"

Herbivore& Herbivore::operator+(Product& product){
    if (product.getProductType() == ProductType::PRODUCT_FRUIT_PLANT){
        this->setWeight(this->getWeight() + product.getAddedWeight());
    } else {
        throw "";
    }

}
