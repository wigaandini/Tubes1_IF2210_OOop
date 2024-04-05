#ifndef __PLANT_HPP_
#define __PLANT_HPP_

#include "Item.hpp"
#include "Product.hpp"
#include <string>
#include <vector>

class Plant : public Item{
private:
    PlantType type;
    int plantId;
    int durationToHarvest;
    int age;
    vector<Product> result;

public:
    Plant();
    Plant(string name, int age);
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
    vector<Product> collect();
};

#endif