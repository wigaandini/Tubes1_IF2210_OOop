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
        T defaultValue;
    public:
        Grid(int row, int col, const T& defaultValue):row(row), col(col), defaultValue(defaultValue){
            buffer.resize(row);
            for(int i = 0; i < row; i++){
                for(int j =0; j < col; j++){
                    string key = generateKey(j);
                    buffer[i][key] = defaultValue;
                }
            }
        }

        ~Grid(){}
        
        string generateKey(int index) {
            string key;
            while (index >= 0) {
                char letter = 'A' + (index % 26);
                key = letter + key;
                index = index / 26 - 1;
            }
            return key;
        }

        void parseInput(const std::string& input, std::string& alphabets, std::string& numbers) {
            alphabets.clear();
            numbers.clear();

            for (char c : input) {
                if (std::isalpha(c)) {
                    alphabets.push_back(c);
                } else if (std::isdigit(c)) {
                    numbers.push_back(c);
                }
            }
        }

        void put(string slot, T item){
            string indexCol, numbers;
            parseInput(slot, indexCol, numbers);
            int indexRow = stoi(numbers);
            buffer.at(indexRow-1).at(indexCol) = item;
        }
        T take(string slot){
            string indexCol, numbers;
            parseInput(slot, indexCol, numbers);
            int indexRow = stoi(numbers);
            T item = buffer.at(indexRow-1).at(indexCol);
            buffer.at(indexRow-1).at(indexCol) = defaultValue;
            return item;
        }
        friend ostream& operator<<(ostream& out, const Grid& G){
            return out;
        }

        void remove(string slot){
            string indexCol, numbers;
            parseInput(slot, indexCol, numbers);
            int indexRow = stoi(numbers);
            buffer.at(indexRow-1).at(indexCol) = defaultValue;
        }

        T see(string slot){
            string indexCol, numbers;
            parseInput(slot, indexCol, numbers);
            int indexRow = stoi(numbers);
            T item = buffer.at(indexRow-1).at(indexCol);
            return item;
        }


};

#endif