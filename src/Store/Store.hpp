#ifndef __STORE_HPP_
#define __STORE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>



#include "../Item/Item.hpp"
#include "../Customer/Customer.hpp"
using namespace std;

class Store{
    private :
        map<string, vector<Item>> items;
        bool checkIsLivingBeings(const string& name) const;
        vector<string> unlimitedAnimalSell;
        vector<string> unlimitedPlantSell;
        vector<string> itemsCanSell() const;

    public :
        Store();
        vector<Item> takeItem(const string& name, const int&);
        Item seeItem(const string& name);
        void addItem(Item& item);
        friend ostream& operator<<(ostream& os, const Store& store);
        void handleCustomerBuy();
        void handleCustomerSell();

};

#endif