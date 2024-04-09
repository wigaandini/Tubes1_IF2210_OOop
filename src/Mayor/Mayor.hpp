#ifndef _MAYOR_HPP_
#define _MAYOR_HPP_

#include "../Player/Player.hpp"
#include "../Customer/Customer.hpp"
#include <vector>
#include <map>

class Mayor: public Player, public Customer{
    public:
        Mayor();
        Mayor(int playerId, string username, float weight, int gulden);
        ~Mayor();
        void taxCollection();
        void buildBuilding();
        bool checkGuldenEnough(int);
        void addPlayer();
        void sell(vector<string>);
        void buy(Item&, int);
        int tax();
};
#endif