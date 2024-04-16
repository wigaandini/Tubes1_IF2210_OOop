#include "Plant.hpp"
#include "../Game/Game.hpp"

map<string, vector<string>> Plant::harvestResult = {
    {"TEAK_TREE", {"TEAK_WOOD"}},
    {"SANDALWOOD_TREE", {"SANDALWOOD_WOOD"}},
    {"ALOE_TREE", {"ALOE_WOOD"}},
    {"IRONWOOD_TREE", {"IRONWOOD_WOOD"}},
    {"APPLE_TREE", {"APPLE"}},
    {"ORANGE_TREE", {"ORANGE"}},
    {"BANANA_TREE", {"BANANA"}},
    {"GUAVA_TREE", {"GUAVA"}},
};

// class Plant
Plant::Plant() : Item()
{
    this->plantId = -1;
    this->durationToHarvest = 0;
    this->age = 0;
}

Plant::Plant(int age, string name) : Item(name, Game::getPlantConfig()[name].code, Game::getPlantConfig()[name].price)
{
    this->type = Game::getPlantConfig()[name].type;
    this->plantId = Game::getPlantConfig()[name].id;
    this->durationToHarvest = Game::getPlantConfig()[name].durationToHarvest;
    this->age = age;
}

Plant::Plant(string name) : Item(name, Game::getPlantConfig()[name].code, Game::getPlantConfig()[name].price)
{
    this->type = Game::getPlantConfig()[name].type;
    this->plantId = Game::getPlantConfig()[name].id;
    this->durationToHarvest = Game::getPlantConfig()[name].durationToHarvest;
    this->age = 0;
}

Plant::~Plant()
{
}

void Plant::setPlantType(PlantType type)
{
    this->type = type;
}

void Plant::setPlantId(int plantId)
{
    this->plantId = plantId;
}

void Plant::setDurationToHarvest(int durationToHarvest)
{
    this->durationToHarvest = durationToHarvest;
}

void Plant::setAge(int age)
{
    this->age = age;
}

PlantType Plant::getPlantType() const
{
    return this->type;
}

int Plant::getPlantId() const
{
    return this->plantId;
}

int Plant::getDurationToHarvest() const
{
    return this->durationToHarvest;
}

int Plant::getAge() const
{
    return this->age;
}

Plant &Plant::operator++()
{
    ++this->age;
    return *this;
}

Plant Plant::operator++(int)
{
    Plant temp = *this;
    ++this->age;
    return temp;
}

vector<shared_ptr<Product>> Plant::collect()
{
    return this->harvester.collect(this->harvestResult, this->name);
}

bool Plant::checkReadyToHarvest()
{
    if (this->age >= this->durationToHarvest)
    {
        return true;
    }
    return false;
}

map<string, vector<string>> &Plant::getHarvestResult()
{
    return harvestResult;
}