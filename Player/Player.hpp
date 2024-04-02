#include "Inventory/Inventory.hpp"
#include "Item/Item.hpp"
#include <iostream>
using namespace std;

class Player{
    private:
        int playerId;
        string username;
        float weight;
        int gulden;
        Inventory inventory;
    public:
        Player(int playerId, string username, float weight, int gulden);
        ~Player();
        void eat(string);
        virtual void buy(string, int) = 0;
        virtual void sell(string) = 0;
        static int countPlayer;
};