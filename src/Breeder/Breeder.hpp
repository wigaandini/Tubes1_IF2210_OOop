#ifndef _BREEDER_HPP_
#define _BREEDER_HPP_

#include "../Player/Player.hpp"
#include "../Ranch/Ranch.hpp"
#include "../Item/Building.hpp"
using namespace std;

#define KTKP_PETERNAK 11

class Breeder: public Player{
    private:
        Ranch *ranch;
    public:
        Breeder();
        Breeder(string username, float weight, int gulden);
        ~Breeder();
        string getType();
        int getWealth();
        void cattle();
        void feedAnimal();
        void sell();
        void buy();
        void harvest();
        int tax();
};
#endif