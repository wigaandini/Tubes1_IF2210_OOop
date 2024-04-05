#ifndef __HERBIVORE_HPP_
#define __HERBIVORE_HPP_

#include "Animal.hpp"
class Herbivore : public Animal{
    public :
        Herbivore(int weight, AnimalConfig& animalConfig ,vector<Product>& result);
        Herbivore(AnimalConfig& animalConfig ,vector<Product>& result);
        Herbivore& operator+(Product& product);
        
};

#endif