#ifndef _RESIDENT_HPP_
#define _RESIDENT_HPP_

#include "../Player/Player.hpp"
#include "../Utils/Utils.hpp"
#include <functional>
#include <limits>
#include <string>
using namespace std;
class Resident : public Player
{

public:
    Resident();
    Resident(string, int, int);
    ~Resident();
    virtual int calculateTax() = 0;
    virtual void harvest() = 0;
    virtual int getWealth() = 0;

protected:
    template <class T, class U>
    void harvest(T &source, map<string, U> &config, map<string, vector<string>> harvestResult, const string &name);

    template <class T, class X, class U>
    void placeTo(T &target, map<string, X> &config, function<bool()> checkInventory, const string &name);
   
};

#include "Resident.tpp"

#endif