#ifndef __CARNIVORE_HPP_
#define __CARNIVORE_HPP_

#include "Animal.hpp"

class Carnivore : public Animal{
    public : 
        Carnivore(string name, int weight);
        Carnivore(string name);
        void eat(const shared_ptr<Product>& product);
        ~Carnivore();

};

#endif