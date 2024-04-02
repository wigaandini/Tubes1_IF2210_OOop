#ifndef __PLANTCONFIG_HPP
#define __PLANTCONFIG_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

enum PlantType {
    MATERIAL_PLANT,
    FRUIT_PLANT
};

class PlantConfig {
    public :
        static map<string, PlantConfig> configs;
        int id;
        string name;
        PlantType type;
        string code;
        int durationToHarvest;
        int price;

        PlantConfig();
        PlantConfig(int id, string name, PlantType type, string code, int durationToHarvest, int price);
        ~PlantConfig();
        static void loadConfigFromFile(const string& filename);
        static PlantConfig getConfigFromName(const string& name);
};

#endif