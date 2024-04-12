#ifndef __HERBIVORE_HPP_
#define __HERBIVORE_HPP_

#include "Animal.hpp"
class Herbivore : public Animal{
    public :
        Herbivore(string name, int weight);
        Herbivore(string name);
        void eat(Product& product);
        virtual ~Herbivore();
        
};

#endif