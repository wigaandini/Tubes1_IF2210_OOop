#include "Herbivore.hpp"

Herbivore::Herbivore(string name, int weight) : Animal(weight, name)
{
}

Herbivore::Herbivore(string name) : Animal(0, name)
{
}

void Herbivore::eat(const shared_ptr<Product> &product)
{
    if (product == nullptr)
    {
        throw NullProductException();
    }
    if (product->getProductType() == ProductType::PRODUCT_FRUIT_PLANT)
    {
        Animal::eat(product);
    }
    else
    {
        throw HerbivoreEatException();
    }
}

Herbivore::~Herbivore()
{
}
