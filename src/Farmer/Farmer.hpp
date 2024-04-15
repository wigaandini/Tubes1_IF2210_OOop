#ifndef _FARMER_HPP_
#define _FARMER_HPP_

#include "../Farm/Farm.hpp"
#include "../Item/Building.hpp"
#include "../Resident/Resident.hpp"

#define KTKP_PETANI 13

class Farmer: public Resident{
    private:
        Farm farm;
    public:
        Farmer();
        Farmer(string username, int weight, int gulden);
        ~Farmer();
        int getWealth();

        Farm& getFarm();
        void plant();
        // vector<shared_ptr<Item>> sell(vector<string>&);
        // void buy(shared_ptr<Item>&, int);
        void harvest();
        int calculateTax();
        void saveFile(const string& filename); 
};

#endif