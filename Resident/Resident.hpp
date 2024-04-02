#include <iostream>
using namespace std;
class Resident{
    public:
        virtual int tax() = 0;
        virtual void harvest(string*) = 0;
};