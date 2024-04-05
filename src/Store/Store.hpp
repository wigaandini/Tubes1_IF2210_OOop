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

    public :
        Store();
        Item& takeItem(const string& name, map<string, AnimalConfig>& animalConfig);
        void addItem(Item& item);
        friend ostream& operator<<(ostream& os, const Store& store);
};

#endif