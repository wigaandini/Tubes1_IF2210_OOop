#ifndef _BREEDER_HPP_
#define _BREEDER_HPP_

#include "../Player/Player.hpp"
#include "../Resident/Resident.hpp"
#include "../Ranch/Ranch.hpp"

class Breeder: public Player{
    private:
        Ranch ranch;
    public:
        Breeder();
        Breeder(int playerId, string username, float weight, int gulden);
        ~Breeder();
        void cattle();
        void feedAnimal();
        void sell(Store&);
        void buy(Store&);
        void harvest();
        int tax();
};
#endif