#ifndef __HERBIVORE_HPP_
#define __HERBIVORE_HPP_

#include "Animal.hpp"
class Herbivore : public Animal{
    public :
        Herbivore& operator+(Product& product);
        
};

#endif