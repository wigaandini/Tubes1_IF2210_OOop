#ifndef __COMMAND_EXCEPTION_HPP__
#define __COMMAND_EXCEPTION_HPP__

#include <exception>
#include <string>
using namespace std;

class NoCommandException : public exception
{

public:
    const char *what() const noexcept override
    {
        return "Perintah tersebut tidak ada!!!";
    }
};


#endif