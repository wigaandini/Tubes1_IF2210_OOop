#ifndef __MAYOR_EXCEPTION_HPP__
#define __MAYOR_EXCEPTION_HPP__

#include <iostream>
#include <exception>
#include <map>
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
        for (auto& material: notEnoughMaterial){
            message += to_string(material.second) + " " + material.first + (i == notEnoughMaterial.size() ? "!" : ", ");
            i++;
        }

    }
    string what()
    {
        
        return message;
    }
};

class NoRecipeException : public exception
{

public:
    
    string what()
    {
        string message = "Kamu tidak punya resep bangunan tersebut!";
        return message;
    }
};
#endif