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
    Inventory &getInventory();
    string &getName();
    string getType();
    virtual ~Player();
    int &getWeight();
    virtual void buy(shared_ptr<Item> &, int, int);
    virtual pair<vector<shared_ptr<Item>>, int> sell(vector<string> &);
    int &getGulden();
    void setGulden(int);
    bool operator==(const Player&);
    void eat();
    void playSlot();
};
#endif