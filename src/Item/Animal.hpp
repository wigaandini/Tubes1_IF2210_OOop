#ifndef __ANIMAL_HPP_
#define __ANIMAL_HPP_

#include "Product.hpp"
#include <string>
#include <vector>

class Animal : public Item{
private:
    int animalId;
    int weight;
    int weighToHarvest;
    // vector<Product> result;
    static map<string, vector<string>> harvestResult;

public:
    Animal();
    Animal(int weight, string name);
    virtual ~Animal();
    void setAnimalType(AnimalType type);
    void setAnimalId(int animalId);
    void setWeight(int weight);
    void setWeightToHarvest(int weightToHarvest);
    int getAnimalId() const;
    int getWeight() const;
    int getWeightToHarvest() const;
    vector<string> collect();
    bool checkReadyToHarvest();
    static map<string, vector<string>>& getHarvestResult();

    virtual void eat(const Product& food);

};

#endif