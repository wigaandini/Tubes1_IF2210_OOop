#ifndef __RESIDENT_HPP__
#define __RESIDENT_HPP__ 

class Resident
{

public:
    virtual int tax() = 0;
    virtual void harvest() = 0;
};


#endif