#ifndef __HERBIVORE_HPP_
#define __HERBIVORE_HPP_

#include "Animal.hpp"
class Herbivore : public Animal{
    public :
        Herbivore(string name, int weight);
        void eat(Product& product);
        ~Herbivore();
        void eat(Product food);
        
};

#endif