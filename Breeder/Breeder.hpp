#include "Player/Player.hpp"
#include "Resident/Resident.hpp"
#include "Ranch/Ranch.hpp"

#ifndef _BREEDER_HPP_
#define _BREEDER_HPP_
class Breeder: public Player, public Resident{
    private:
        Ranch ranch;
    public:
        Breeder();
        Breeder(int playerId, string username, float weight, int gulden);
        ~Breeder();
        void cattle(string, string);
        void feedAnimal(string, string);
        void sell(string *listSlotItem);
        void buy(string slotItem, int quantity);
        void harvest(string*);
        int tax();
};
#endif