#ifndef __PLAYER_EXCEPTION_HPP__
#define __PLAYER_EXCEPTION_HPP__

#include <exception>
using namespace std;

class CannotSellBuildingException : public exception
{
public:
    const char *what() const noexcept override
    {

        return "Tidak bisa menjual bangunan!!!";
    }
};



class NotEnoughGuldenException : public exception
{
public:
    const char *what() const noexcept override
    {

        return "Gulden tidak mencukupi!!!";
    }
};

class InventoryNotEnoughException : public exception
{
public:
    const char *what() const noexcept override
    {

        return "Inventory tidak cukup!!!!";
    }
};

#endif