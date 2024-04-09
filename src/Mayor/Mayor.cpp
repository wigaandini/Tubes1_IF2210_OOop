#include "Mayor.hpp"
#include "../Item/Building.hpp"

Mayor::Mayor() : Player()
{
}

Mayor::~Mayor()
{
}

int Mayor::tax()
{
    return 0;
}

void Mayor::buy(Item& item, int quantity)
{
    if (item.getPrice() * quantity > this->gulden) {
        throw ""; //uang  tidak cukup
    }

    if (const Building *building = dynamic_cast<const Building *>(&item)){
        throw ""; //tidak bisa beli building
    }

    if (this->inventory->countEmpty() < quantity) {
        throw ""; //Penyimpanan tidak cukup
    }

    this->gulden -= item.getPrice() * quantity;
    
}

void Mayor::sell(vector<string> slots)
{ 
    vector<Item> items;
    for (string slot : slots) {

        if (this->inventory->isEmpty(slot)){
            throw ""; //empty slot
        }


    }
}