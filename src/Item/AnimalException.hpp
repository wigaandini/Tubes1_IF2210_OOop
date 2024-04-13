#ifndef __ANIMAL_EXCEPTION_HPP__
#define __ANIMAL_EXCEPTION_HPP__

#include <exception>
#include <string>
using namespace std;

class NullProductException : public exception
{

public:
    const char *what() const noexcept override
    {
        return "Item tersebut bukanlah produk!!!";
    }
};


class CarnivoreEatException : public exception
{

public:
    const char *what() const noexcept override
    {
        return "Hewan karnivora tidak bisa memakan makanan tersebut dan hanya bisa makan daging (animal product)";
    }
};

class HerbivoreEatException : public exception
{

public:
    const char *what() const noexcept override
    {
        return "Hewan herbivora tidak bisa memakan makanan tersebut dan hanya bisa makan tumbuhan (fruit product)";
    }
};

class OmnivoreEatException : public exception
{

public:
    const char *what() const noexcept override
    {
        return "Hewan omnivora tidak bisa memakan makanan tersebut, hanya bisa makan tumbuhan (fruit product) dan daging (animal product)";
    }
};


#endif