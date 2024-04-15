#include "Harvester.hpp"

vector<shared_ptr<Product>> Harvester::collect(const map<string, vector<string>> &harvestData, const string &name)
    {
        vector<shared_ptr<Product>> tempP;
        for (auto &productName : harvestData.at(name))
        {
            tempP.push_back(make_shared<Product>(productName));
        }
        return tempP;
    }