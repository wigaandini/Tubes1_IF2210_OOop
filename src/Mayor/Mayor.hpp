#ifndef _MAYOR_HPP_
#define _MAYOR_HPP_

#include "../Player/Player.hpp"
#include "../Item/Building.hpp"
#include "../configClass/RecipeConfig.hpp"

#include <vector>
#include <map>

class Mayor: public Player{
    public:
        Mayor();
        Mayor(string username, float weight, int gulden);
        ~Mayor();
        string getType();
        void taxCollection(vector<Player*>);
        int getWealth();
        void buildBuilding(map<string, RecipeConfig>);
        bool canBuild(string, map<string, RecipeConfig>);
        void addPlayer(vector<Player*>&);
        void sell();
        void buy();
        int tax();
};
#endif