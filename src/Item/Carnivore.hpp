#ifndef __CARNIVORE_HPP_
#define __CARNIVORE_HPP_

#include "Animal.hpp"

class Carnivore : public Animal{
    public : 
        void eat(Product product);
};

#endif