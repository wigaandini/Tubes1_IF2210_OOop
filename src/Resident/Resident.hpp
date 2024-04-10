#ifndef _RESIDENT_HPP_
#define _RESIDENT_HPP_

#include "../Player/Player.hpp"
class Resident : public Player
{

public:
    Resident();
    Resident(string, int, int);
    ~Resident();
    virtual int tax() = 0;
    virtual void harvest() = 0;
    virtual int getWealth() = 0;
};

#endif