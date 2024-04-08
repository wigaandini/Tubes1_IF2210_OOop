#ifndef _MAYOR_HPP_
#define _MAYOR_HPP_

#include "../Player/Player.hpp"
#include <vector>
#include <map>

class Mayor: public Player{
    public:
        Mayor();
        Mayor(string username, float weight, int gulden);
        ~Mayor();
        void taxCollection();
        void buildBuilding();
        bool checkGuldenEnough(int);
        void addPlayer();
        void sell();
        void buy();
        int tax();
};
#endif