#include "Player/Player.hpp"
#ifndef _MAYOR_HPP_
#define _MAYOR_HPP_
class Mayor: public Player{
    public:
        Mayor();
        Mayor(int playerId, string username, float weight, int gulden);
        ~Mayor();
        void taxCollection(int);
        void buildBuilding(string);
        bool checkGuldenEnough(int);
        void addPlayer();
        void sell(string *listSlotItem);
        void buy(string slotItem, int quantity);
};
#endif