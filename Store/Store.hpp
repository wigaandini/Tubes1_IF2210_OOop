#ifndef __STORE_HPP_
#define __STORE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Item.hpp"
using namespace std;

class Store{
    private :
        map<string, vector<Item>> items;
        static Store store;

    public :
        Store();
        Store(const Store&);
        void addItem(Item item);
        static Store getInstance();
        Item takeItem(string name);
        friend ostream& operator<<(ostream& os, Store store);
};

#endif