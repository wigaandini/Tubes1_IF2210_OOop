#ifndef __ANIMAL_HPP_
#define __ANIMAL_HPP_

#include "../Item/Item.hpp"
#include "../Product/Product.hpp"
#include <string>

class Animal : public Item{
private:
    AnimalType type;
    int animalId;
    float weight;
    float weighToHarvest;

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
};

#endif