#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "../Inventory/Inventory.hpp"
#include "../Store/Store.hpp"
using namespace std;

class Player
{
protected:
    static int countIdPlayer;
    int playerId;
    string username;
    int weight;
    int gulden;
    Inventory* inventory;

public:
    Player();
    Player(string username, int weight, int gulden);
    virtual ~Player();
    void eat();
    virtual void buy() ;
    virtual void sell() ;
    int getGulden() const;
    Inventory* getInventory() const ;
};
#endif