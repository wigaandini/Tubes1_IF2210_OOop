#ifndef _GRIDEXCEPTION_HPP
#define _GRIDEXCEPTION_HPP

#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundException: public exception{
    public:
    const char*  what() const noexcept override{
        return "Slot penyimpanan tidak tersedia";
    }
};

class SlotOccupiedException: public exception{
    public:
    const char*  what() const noexcept override{
        return "Slot tersebut telah diisi";
    }
};

class SlotEmptyException: public exception{
    public:
    const char*  what() const noexcept override{
        return "Slot tersebut kosong";
    }
};

class GridFullException: public exception{
    public:
    const char*  what() const noexcept override{
        return "Slot penyimpanan telah penuh";
    }
};

class GridEmptyException: public exception{
    public:
    const char*  what() const noexcept override{
        return "Slot penyimpanan kosong";
    }
};

#endif


