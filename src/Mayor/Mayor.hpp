#ifndef _MAYOR_HPP_
#define _MAYOR_HPP_

#include "../Player/Player.hpp"
#include "../Item/Building.hpp"
#include "../configClass/RecipeConfig.hpp"
#include "../Utils/Utils.hpp"
#include <vector>
#include <map>

class Mayor : public Player
{

public:
    Mayor();
    Mayor(string username, float weight, int gulden);
    ~Mayor();
    string getType();
    void taxCollection();
    void buildBuilding();
    void addPlayer();
    pair<vector<shared_ptr<Item>>, int> sell(vector<string> &);
    void buy(shared_ptr<Item> &, int);
};
#endif