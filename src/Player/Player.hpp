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
    string type;
    string username;
    int weight;
    int gulden;
    Inventory inventory;

public:
    Player();
    Player(string username, int weight, int gulden);
    Inventory& getInventory();
    void setInventory(Inventory& inventory);
    string getName() const;
    virtual ~Player();
    string getName();
    int getWeight();
    virtual string getType() = 0;
    virtual int getWealth() = 0;
    int getGulden();
    void setGulden(int);
    void eat();
    virtual void buy() = 0;
    virtual void sell() = 0;
    virtual int tax() = 0;
};
#endif