#ifndef _FARMER_HPP_
#define _FARMER_HPP_

#include "../Player/Player.hpp"
#include "../Farm/Farm.hpp"
#include "../Item/Building.hpp"

#define KTKP 13

class Farmer: public Player{
    private:
        Farm *farm;
    public:
        Farmer();
        Farmer(string username, int weight, int gulden);
        ~Farmer();
        string getType();
        int getWealth();
        void plant();
        void sell();
        void buy();
        void harvest();
        int tax();
};

#endif