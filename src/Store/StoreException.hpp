#ifndef __STORE_EXCEPTION_HPP__
#define __STORE_EXCEPTION_HPP__

#include <exception>
using namespace std;

class StockNotEnoughException : public exception
{
public:
    const char *what() const noexcept override
    {

        return "Jumlah stock pada toko tidak cukup!!!";
    }
};

class WrongSlotsSizeException : public exception
{
public:
    const char *what() const noexcept override
    {

        return "Jumlah slots penyimpanan tidak sesuai!!!";
    }
};



#endif