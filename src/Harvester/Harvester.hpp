#ifndef _HARVESTER_HPP_
#define _HARVESTER_HPP_

#include <vector>
#include <map>
#include <memory>
#include "../Item/Product.hpp"
using namespace std;

class Harvester
{
public:
    vector<shared_ptr<Product>> collect(const map<string, vector<string>> &harvestData, const string &name)
    {
        vector<shared_ptr<Product>> tempP;
        for (auto &productName : harvestData.at(name))
        {
            tempP.push_back(make_shared<Product>(productName));
        }
        return tempP;
    }
};

#endif