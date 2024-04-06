#ifndef _MAINCONFIG_HPP_
#define _MAINCONFIG_HPP_

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class MainConfig{
    public:
        int guldenForWin;
        int weightPlayerToWin;
        int inventorySize[2];
        int farmSize[2];
        int ranchSize[2];

        MainConfig();
        MainConfig(int guldenForWin,int weightPlayerToWin,int inventorySize[2],int farmSize[2],int ranchSize[2]);
        ~MainConfig();
};

#endif