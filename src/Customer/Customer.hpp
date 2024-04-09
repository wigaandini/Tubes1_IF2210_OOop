#ifndef _CUSTOMER_HPP_
#define _CUSTOMER_HPP_

#include "../Item/Item.hpp"
class Customer
{
public:
    virtual void buy(Item&, int) = 0;
    virtual void sell(vector<string>&) = 0;
};

#endif