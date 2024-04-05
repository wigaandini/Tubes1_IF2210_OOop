#ifndef _FARMER_HPP_
#define _FARMER_HPP_

#include "../Player/Player.hpp"
#include "../Farm/Farm.hpp"

class Farmer: public Player {
    private:
        Farm farm;
    public:
        Farmer();
        Farmer(int playerId, string username, float weight, int gulden);
        ~Farmer();
        void plant();
        void sell(Store&);
        void buy(Store&);
        void harvest();
        int tax();
};

#endif