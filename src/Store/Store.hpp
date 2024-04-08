#ifndef __STORE_HPP_
#define __STORE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>



#include "../Item/Item.hpp"
using namespace std;

class Store{
    private :
        map<string, vector<shared_ptr<Item>>> items;
        bool checkIsLivingBeings(const string& name);

    public :
        Store();
        map<string, vector<shared_ptr<Item>>> getItems() const;
        vector<shared_ptr<Item>> takeItem(const string& name, const int&);
        void addItem(shared_ptr<Item> item);
        friend ostream& operator<<(ostream& os, const Store& store);
        ~Store();
};

#endif