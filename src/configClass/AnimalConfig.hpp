#ifndef _ANIMALCONFIG_HPP_
#define _ANIMALCONFIG_HPP_

#include <string>
#include <map>
using namespace std;

enum class AnimalType
{
    HERBIVORE,
    CARNIVORE,
    OMNIVORE
};
class AnimalConfig
{
public:
    static map<string,AnimalConfig> configs;
    int id;
    string name;
    AnimalType type;
    
    
    int price;
    string code;
    int weightToHarvest;

    AnimalConfig();
    AnimalConfig(int id, string name, AnimalType type, int price, string code, int weightToHarvest);
    ~AnimalConfig();
    static void loadConfigFromFile(string filename);
    static AnimalConfig getConfigFromName(const string& name);
};

#endif