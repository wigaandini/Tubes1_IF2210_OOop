#ifndef __MAYOR_EXCEPTION_HPP__
#define __MAYOR_EXCEPTION_HPP__

#include <iostream>
#include <exception>
#include <map>
#include <string>
using namespace std;

class NotEnoughMaterialException : public exception
{
private:
    string message;

public:
    NotEnoughMaterialException(map<string, int> notEnoughMaterial) : exception()
    {
        unsigned int i = 1;
        message = "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
        for (auto &material : notEnoughMaterial)
        {
            message += to_string(material.second) + " " + material.first + (i == notEnoughMaterial.size() ? "!" : ", ");
            i++;
        }
    }
    const char *what() const noexcept override
    {

        return message.c_str();
    }
};

class NoRecipeException : public exception
{

public:
    const char *what() const noexcept override
    {
        return "Kamu tidak punya resep bangunan tersebut!";
    }
};

class CannotBuyBuildingException : public exception
{
public:
    const char *what() const noexcept override
    {

        return "Tidak bisa membeli bangunan!!!";
    }
};

#endif