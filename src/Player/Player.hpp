#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "../Inventory/Inventory.hpp"
#include "../Item/Item.hpp"
#include "../Store/Store.hpp"
using namespace std;

class Player
{
private:
    static int countIdPlayer;
    int playerId;
    string username;
    int weight;
    int gulden;
    Inventory* inventory;

public:
    Player();
    Player(string username, int weight, int gulden);
    ~Player();
    void eat();
    virtual int tax() = 0;
    virtual void buy(Store&) = 0;
    virtual void sell(Store&) = 0;
};
#endif