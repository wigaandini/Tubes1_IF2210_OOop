#include "MainConfig.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

MainConfig MainConfig::config;

MainConfig::MainConfig(){

}
MainConfig::MainConfig(int guldenForWin,int weightPlayerToWin,int inventorySize[2],int farmSize[2],int ranchSize[2]){
    this->guldenForWin = guldenForWin;
    this->weightPlayerToWin = weightPlayerToWin;
    this->inventorySize[0] = inventorySize[0];
    this->inventorySize[1] = inventorySize[1];
    this->farmSize[0] = farmSize[0];
    this->farmSize[1] = farmSize[1];
    this->ranchSize[0] = ranchSize[0];
    this->ranchSize[1] = ranchSize[1];
}

MainConfig::~MainConfig(){

}

void MainConfig::loadConfigFromFile(const string& filename){
    ifstream file(filename);
    int guldenForWin,weightPlayerToWin;
    int inventorySize[2];
    int farmSize[2];
    int ranchSize[2];

    file >> guldenForWin >> weightPlayerToWin;
    file >> inventorySize[0] >> inventorySize[1];
    file >> farmSize[0] >> farmSize[1];
    file >> ranchSize[0] >> ranchSize[1];

    
    config = MainConfig(guldenForWin, weightPlayerToWin, inventorySize, farmSize, ranchSize);  
}

MainConfig MainConfig::getConfig() {
    return config;
}