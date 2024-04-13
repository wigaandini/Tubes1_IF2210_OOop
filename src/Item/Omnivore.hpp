#ifndef __OMNIVORE_HPP_
#define __OMNIVORE_HPP_

#include "Animal.hpp"

class Omnivore : public Animal{
    public :
        Omnivore(string name, int weight);
        Omnivore(string name);
        void eat(const shared_ptr<Product>& product);
        ~Omnivore();
        
};

#endif