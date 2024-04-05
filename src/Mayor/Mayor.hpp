#ifndef _MAYOR_HPP_
#define _MAYOR_HPP_

#include "../Player/Player.hpp"
#include <vector>
#include <map>
#include "../configClass/RecipeConfig.hpp"

class Mayor: public Player{
    public:
        Mayor();
        Mayor(int playerId, string username, float weight, int gulden);
        ~Mayor();
        void taxCollection(vector<Player>&);
        void buildBuilding(map<string, RecipeConfig>);
        bool checkGuldenEnough(int);
        void addPlayer(vector<Player>&);
        void sell(Store&);
        void buy(Store&);
};
#endif