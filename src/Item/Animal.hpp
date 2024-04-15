#ifndef __ANIMAL_HPP_
#define __ANIMAL_HPP_

#include "AnimalException.hpp"
#include "../Harvester/Harvester.hpp"
using namespace std;

class Animal : public Item{
private:
    int animalId;
    int weight;
    int weighToHarvest;
    Harvester harvester;
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
    vector<shared_ptr<Product>> collect();
    bool checkReadyToHarvest();
    static map<string, vector<string>>& getHarvestResult();

    virtual void eat(const shared_ptr<Product>& food);

};

#endif