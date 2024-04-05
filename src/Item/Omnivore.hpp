#ifndef __OMNIVORE_HPP_
#define __OMNIVORE_HPP_

#include "Animal.hpp"

class Omnivore : public Animal{
    public :
        Omnivore(string name, int weight);
        Omnivore(string name);
        Omnivore& operator+(Product& product);
        
};

#endif