#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<class T>
class Grid{
    private:
        vector<map<string, T>> buffer;
        int row;
        int col;
    public:
        Grid(int row, int col){
            this->row = row; this->col = col;
            buffer.resize(row);
        }
        ~Grid(){}
        void put(string slot, T item){
            char indexCol = slot[0];
            int indexRow = stoi(slot.substr(1));
            if(int(indexCol - 'A') + 1 > col || indexRow > row){
                throw "Index out of bound error";
            }
            buffer[indexRow-1][indexCol] = item;
        }
        T take(string slot){
            char indexCol = slot[0];
            int indexRow = stoi(slot.substr(1));
            if(int(indexCol - 'A') + 1 > col || indexRow > row){
                throw "Index out of bound error";
            }
            typename map<string, T>::iterator itr = buffer[indexRow-1].find(indexCol);
            if(itr == buffer[indexRow-1].end()){
                throw "Slot is empty";
            }
            T item = buffer[indexRow-1][indexCol];
            buffer[indexRow-1].erase(indexCol);
            return item;
        }
        friend ostream& operator<<(ostream& out, const Grid& G){
            return out;
        }

        void remove(string slot){
            char indexCol = slot[0];
            int indexRow = stoi(slot.substr(1));
            if(int(indexCol - 'A') + 1 > col || indexRow > row){
                throw "Index out of bound error";
            }
            buffer[indexRow-1].erase(indexCol);
        }

        T see(string slot){
            char indexCol = slot[0];
            int indexRow = stoi(slot.substr(1));
            if(int(indexCol - 'A') + 1 > col || indexRow > row){
                throw "Index out of bound error";
            }
            typename map<string, T>::iterator itr = buffer[indexRow-1].find(indexCol);
            if(itr == buffer[indexRow-1].end()){
                throw "Slot is empty";
            }
            T item = buffer[indexRow-1][indexCol];
            return item;
        }


};

#endif