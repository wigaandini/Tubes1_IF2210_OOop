#ifndef __PLANT_HPP_
#define __PLANT_HPP_

#include "../Item/Item.hpp"
#include <string>

class Plant : public Item{
private:
    PlantType type;
    int plantId;
    int durationToHarvest;
    int age;

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
};

#endif