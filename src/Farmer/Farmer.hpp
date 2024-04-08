#ifndef _FARMER_HPP_
#define _FARMER_HPP_

#include "../Player/Player.hpp"
#include "../Farm/Farm.hpp"

class Farmer: public Player{
    private:
        Farm *farm;
    public:
        Farmer();
        Farmer(string username, int weight, int gulden);
        ~Farmer();
        void plant();
        void sell();
        void buy();
        void harvest();
        int tax();
};

#endif