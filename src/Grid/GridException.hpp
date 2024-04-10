#ifndef _GRIDEXCEPTION_HPP
#define _GRIDEXCEPTION_HPP

#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundException: public exception{
    string what(){
        return "Slot penyimpanan tidak tersedia";
    }
};

class SlotOccupiedException: public exception{
    string what(){
        return "Slot tersebut telah diisi";
    }
};

class SlotEmptyException: public exception{
    string what(){
        return "Slot tersebut kosong";
    }
};

class GridFullException: public exception{
    string what(){
        return "Slot penyimpanan telah penuh";
    }
};

class GridEmptyException: public exception{
    string what(){
        return "Slot penyimpanan kosong";
    }
};

#endif


