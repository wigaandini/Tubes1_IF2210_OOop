#ifndef __CARNIVORE_HPP_
#define __CARNIVORE_HPP_

#include "Animal.hpp"

class Carnivore : public Animal{
    public : 
        Carnivore(string name, int weight);
        Carnivore& operator+(Product& product);
};

#endif