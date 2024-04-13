#include "Carnivore.hpp"

Carnivore::Carnivore(string name, int weight) : Animal(weight, name)
{
}

Carnivore::Carnivore(string name) : Animal(0, name)
{
}

void Carnivore::eat(const shared_ptr<Product> &product)
{
    if (product == nullptr)
    {
        throw NullProductException();
    }
    if (product->getProductType() == ProductType::PRODUCT_ANIMAL)
    {
        Animal::eat(product);
    }
    else
    {
        throw CarnivoreEatException();
    }
}

Carnivore::~Carnivore()
{
}
