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
    Inventory* getInventory();
    void setInventory(Inventory& inventory);
    string getName() const;
    virtual ~Player();
    void eat();
    virtual void buy() ;
    virtual void sell() ;
};
#endif