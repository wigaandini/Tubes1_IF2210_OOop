#include "Omnivore.hpp"


Omnivore::Omnivore(string name, int weight):Animal(weight,name){

}

Omnivore::Omnivore(string name):Animal(0,name){

}


void Omnivore::eat(Product &product)
{
    if (product.getProductType() != ProductType::PRODUCT_ANIMAL && product.getProductType() != ProductType::PRODUCT_FRUIT_PLANT  )
    {
        throw "";
    }
    else
    {
        Animal::eat(product);
    }

}

Omnivore::~Omnivore(){

}