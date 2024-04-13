#ifndef _GRIDEXCEPTION_HPP
#define _GRIDEXCEPTION_HPP

#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundException : public exception
{
private:
    string problemSlot;
    string message;

public:
    IndexOutOfBoundException() : exception(), problemSlot(""), message("Slot tersebut tidak tersedia") {
    }

    IndexOutOfBoundException(const string &pSlot) : exception(), problemSlot(pSlot)  {
        string slot = int(this->problemSlot.size()) > 0 ? "(" + this->problemSlot + ")" : "";
        message = "Slot tersebut tidak tersedia " + slot;
    }

    ~IndexOutOfBoundException() {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class SlotOccupiedException : public exception
{
private:
    string problemSlot;
    string message;


public:
    SlotOccupiedException() : exception(), problemSlot(""), message("Slot tersebut telah diisi")  {}

    SlotOccupiedException(const string &pSlot) : exception(), problemSlot(pSlot)  {
        string slot = int(this->problemSlot.size()) > 0 ? "(" + this->problemSlot + ")" : "";
        this->message = "Slot tersebut telah diisi " + slot;
    }

    ~SlotOccupiedException() {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class SlotEmptyException : public exception
{
private:
    string problemSlot;
    string message;


public:
    SlotEmptyException() : exception(), problemSlot(""), message("Slot tersebut kosong")  {}

    SlotEmptyException(const string &pSlot) : exception(), problemSlot(pSlot)  {
        string slot = int(this->problemSlot.size()) > 0 ? "(" + this->problemSlot + ")" : "";
        message = "Slot tersebut kosong " + slot;
    }

    ~SlotEmptyException() {}
    const char *what() const noexcept override
    {
        
        return message.c_str();
    }
};

class GridFullException : public exception
{
public:
    GridFullException() : exception() {}

    ~GridFullException() {}
    const char *what() const noexcept override
    {
        return "Grid telah penuh";
    }
};

class GridEmptyException : public exception
{
public:
    GridEmptyException() : exception() {}

    ~GridEmptyException() {}
    const char *what() const noexcept override
    {
        return "Grid kosong";
    }
};

class InvalidSlotFormatException : public exception
{
public:
    InvalidSlotFormatException() : exception() {}

    ~InvalidSlotFormatException() {}
    const char *what() const noexcept override
    {
        return "Masukan slot yang diberikan tidak sesuai dengan format!!!";
    }
};

#endif
