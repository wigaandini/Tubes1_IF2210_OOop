#include <iostream>
#ifndef _RESIDENT_HPP_
#define _RESIDENT_HPP_
using namespace std;


class Resident{
    public:
        virtual int tax() = 0;
        virtual void harvest(string*) = 0;
};
#endif