#ifndef _FARMER_HPP_
#define _FARMER_HPP_

#include "../Player/Player.hpp"
#include "../Farm/Farm.hpp"
#include "../Resident/Resident.hpp"

class Farmer : public Player, public Resident
{
private:
    Farm *farm;

public:
    Farmer();
    Farmer(string username, int weight, int gulden);
    ~Farmer();
    void plant();
    void sell();
    void buy(Item &, int);
    void harvest();
    int tax();
};

#endif