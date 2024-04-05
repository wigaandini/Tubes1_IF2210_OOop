#include "Omnivore.hpp"

Omnivore &Omnivore::operator+(Product &product)
{
    if (product.getProductType() != ProductType::PRODUCT_MATERIAL_PLANT)
    {
        throw "";
    }
    else
    {
        this->setWeight(this->getWeight() + product.getAddedWeight());
    }
}
