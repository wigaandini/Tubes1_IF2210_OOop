#ifndef __PLANT_HPP_
#define __PLANT_HPP_

#include "Item.hpp"
#include "../Harvester/Harvester.hpp"

class Plant : public Item
{
private:
    PlantType type;
    int plantId;
    int durationToHarvest;
    int age;
    Harvester harvester;
    static map<string, vector<string>> harvestResult;

public:
    Plant();
    Plant(int age, string name);
    ~Plant();
    Plant(string name);
    void setPlantType(PlantType type);
    void setPlantId(int plantId);
    void setDurationToHarvest(int durationToHarvest);
    void setAge(int age);
    PlantType getPlantType() const;
    int getPlantId() const;
    int getDurationToHarvest() const;
    int getAge() const;
    Plant &operator++();
    Plant operator++(int);
    vector<shared_ptr<Product>> collect();
    bool checkReadyToHarvest();
    static map<string, vector<string>> &getHarvestResult();
};

#endif