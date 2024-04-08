#ifndef _MAYOR_HPP_
#define _MAYOR_HPP_

#include "../Player/Player.hpp"
#include "../Item/Building.hpp"
#include "../configClass/RecipeConfig.hpp"

#include <vector>
#include <map>

class Mayor: public Player{
    private:
        vector<Building> buildings;
    public:
        Mayor();
        Mayor(int playerId, string username, float weight, int gulden);
        ~Mayor();
        string getType();
        void taxCollection(vector<Player*>);
        void buildBuilding(map<string, RecipeConfig>);
        bool checkGuldenEnough(int);
        void addPlayer();
        void sell();
        void buy();
        int tax();
};
#endif