#ifndef _BREEDER_HPP_
#define _BREEDER_HPP_

#include "../Ranch/Ranch.hpp"
#include "../Item/Building.hpp"
// #include "../Customer/Customer.hpp"
#include "../Resident/Resident.hpp"
using namespace std;

#define KTKP_PETERNAK 11

class Breeder: public Resident{
    private:
        Ranch ranch;
    public:
        Breeder();
        Breeder(string username, float weight, int gulden);
        ~Breeder();
        string getType();
        int getWealth();
        void cattle();
        void feedAnimal();
        // vector<shared_ptr<Item>> sell(vector<string>&);
        // void buy(shared_ptr<Item>&, int);
        void harvest();
        int tax();
        Ranch& getRanch();
};
#endif