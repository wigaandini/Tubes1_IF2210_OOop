#include "Player/Player.hpp"
#include "Resident/Resident.hpp"
#include "Farm/Farm.hpp"

#ifndef _FARMER_HPP_
#define _FARMER_HPP_
class Farmer: public Player, public Resident{
    private:
        Farm farm;
    public:
        Farmer();
        Farmer(int playerId, string username, float weight, int gulden);
        ~Farmer();
        void plant(string, string);
        void sell(string *listSlotItem);
        void buy(string slotItem, int quantity);
        void harvest(string*);
        int tax();
};

#endif