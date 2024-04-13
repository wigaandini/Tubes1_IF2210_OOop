#include "Omnivore.hpp"


Omnivore::Omnivore(string name, int weight):Animal(weight,name){

}

Omnivore::Omnivore(string name):Animal(0,name){

}


void Omnivore::eat(const shared_ptr<Product>&product)
{
    if (product == nullptr) {
        throw NullProductException();
    }
    if (product->getProductType() != ProductType::PRODUCT_ANIMAL && product->getProductType() != ProductType::PRODUCT_FRUIT_PLANT  )
    {
        throw OmnivoreEatException();
    }
    else
    {
        Animal::eat(product);
    }

}

Omnivore::~Omnivore(){

}