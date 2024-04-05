#ifndef __ANIMAL_HPP_
#define __ANIMAL_HPP_

#include "Item.hpp"
#include "Product.hpp"
#include <string>
#include <vector>

class Animal : public Item{
private:
    int animalId;
    int weight;
    int weighToHarvest;
    vector<Product> result;

public:
    Animal();
    Animal(int weight, AnimalConfig& animalConfig ,vector<Product>& result);
    Animal(AnimalConfig& animalConfig ,vector<Product>& result);
    void setAnimalType(AnimalType type);
    void setAnimalId(int animalId);
    void setWeight(int weight);
    void setWeightToHarvest(int weightToHarvest);
    AnimalType getAnimalType() const;
    int getAnimalId() const;
    int getWeight() const;
    int getWeightToHarvest() const;
    vector<Product>& collect();
};

#endif