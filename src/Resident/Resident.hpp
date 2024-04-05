#ifndef _RESIDENT_HPP_
#define _RESIDENT_HPP_

#include <iostream>
using namespace std;


class Resident{
    public:
        virtual int tax() = 0;
        virtual void harvest(string*) = 0;
};
#endif