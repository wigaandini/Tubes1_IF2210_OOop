#ifndef __OMNIVORE_HPP_
#define __OMNIVORE_HPP_

#include "Animal.hpp"

class Omnivore : public Animal{
    public :
        Omnivore(string name, int weight);
        Omnivore& operator+(Product& product);
        
};

#endif