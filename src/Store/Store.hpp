#ifndef __STORE_HPP_
#define __STORE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>



#include "../Item/Item.hpp"
using namespace std;

class Store{
    private :
        map<string, vector<Item>> items;
        bool checkIsLivingBeings(const string& name);

    public :
        Store();
        vector<Item> takeItem(const string& name, const int&);
        void addItem(Item& item);
        friend ostream& operator<<(ostream& os, const Store& store);

};

#endif