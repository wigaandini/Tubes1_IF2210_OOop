#ifndef _MAINCONFIG_HPP_
#define _MAINCONFIG_HPP_

#include <string>
using namespace std;

class MainConfig{
    public:
        static MainConfig config;
        int guldenForWin;
        int weightPlayerToWin;
        int inventorySize[2];
        int farmSize[2];
        int ranchSize[2];

        MainConfig();
        MainConfig(int guldenForWin,int weightPlayerToWin,int inventorySize[2],int farmSize[2],int ranchSize[2]);
        ~MainConfig();

        static void loadConfigFromFile(const string& filename);
        static MainConfig getConfig();
};

#endif