#ifndef __ANIMAL_HPP_
#define __ANIMAL_HPP_

#include "Item.hpp"
#include "Product.hpp"
#include <string>
#include <vector>

class Animal : public Item{
private:
    int animalId;
    float weight;
    float weighToHarvest;
    vector<Product> result;

public:
    Animal();
    Animal(string name, float weight);
    void setAnimalType(AnimalType type);
    void setAnimalId(int animalId);
    void setWeight(float weight);
    void setWeightToHarvest(float weightToHarvest);
    AnimalType getAnimalType() const;
    int getAnimalId() const;
    float getWeight() const;
    float getWeightToHarvest() const;
    Animal &operator+(Product product);
    void eat(Product product);
};

#endif