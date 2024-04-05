#ifndef __ITEM_HPP_
#define __ITEM_HPP_

#include <iostream>
#include <string>
#include <map>
#include "../configClass/PlantConfig.hpp"
#include "../configClass/AnimalConfig.hpp"
#include "../configClass/ProductConfig.hpp"
using namespace std;

class Item
{
protected:
    static int countIdItem;
    int itemId;
    string name;
    string code;
    int price;

public:
    Item();
    Item(string name, string code, int price);
    void setItemId(int itemId);
    void setName(string name);
    void setCode(string code);
    void setPrice(int price);
    int getItemId() const;
    string getName() const;
    string getCode() const;
    int getPrice() const;
};

class Plant : public Item
{
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

class Animal : public Item
{
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

class Product : public Item
{
private:
    ProductType type;
    int productId;
    string origin;
    float addedWeight;

public:
    Product();
    Product(string name);
    void setProductType(ProductType type);
    void setProductId(int productId);
    void setOrigin(float origin);
    void setAddedWeight(float addedWeight);
    ProductType getProductType() const;
    int getProductId() const;
    string getOrigin() const;
    float getAddedWeight() const;
};

class Building : public Item
{
private:
    map<string, int> material;
public:
    Building();
    Building(string name);
    int getQuantityPerMaterial(string materialName) const;
    map<string, int> getBuildingMaterial() const;
};

#endif