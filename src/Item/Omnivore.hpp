#ifndef __OMNIVORE_HPP_
#define __OMNIVORE_HPP_

#include "Animal.hpp"

class Omnivore : public Animal{
    public :
        void eat(Product product);
};

#endif