#ifndef _MAYOR_HPP_
#define _MAYOR_HPP_

#include "../Player/Player.hpp"
#include "../Item/Building.hpp"
#include "../configClass/RecipeConfig.hpp"

#include <vector>
#include <map>

class Mayor : public Player
{
private:
    string toLower(string);

public:
    Mayor();
    Mayor(string username, float weight, int gulden);
    ~Mayor();
    string getType();
    void taxCollection();
    // int getWealth();
    void buildBuilding();
    // void canBuild(string);
    void addPlayer();
    // void taxCollection();
    // void buildBuilding();
    // bool checkGuldenEnough(int);
    // void addPlayer();
    pair<vector<shared_ptr<Item>>, int> sell(vector<string> &);
    void buy(shared_ptr<Item> &, int);
    int tax();
};
#endif