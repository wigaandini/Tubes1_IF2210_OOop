#ifndef _LOAD_EXCEPTION_HPP
#define _LOAD_EXCEPTION_HPP

#include <iostream>
#include <exception>

using namespace std;

class FileNotFoundException : public exception
{
private:
    string filename;
    string message;

public:
    FileNotFoundException() : exception(), filename(""), message("File tersebut tidak tersedia") {
    }

    FileNotFoundException(const string &filename) : exception(), filename(filename)  {
        string file = int(this->filename.size()) > 0 ? this->filename : "";
        message = "File " + file + " tidak ditemukan!!";
    }

    ~FileNotFoundException() {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class WrongFormatException : public exception
{
private:
    string filename;
    string message;

public:
    WrongFormatException() : exception(), filename(""), message("Terdapat kesalahan format pada file yang diberikan!!!") {
    }

    WrongFormatException(const string &filename) : exception(), filename(filename)  {
        string file = int(this->filename.size()) > 0 ? this->filename : "";
        message = "Terdapat kesalahan format pada file " + file + " yang diberikan!!!";
    }

    ~WrongFormatException() {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};



#endif
