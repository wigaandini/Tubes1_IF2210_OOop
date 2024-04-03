#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

template<class T>
class Grid {
private:
    vector<map<string, T>> buffer;
    int row;
    int col;
    T defaultValue;

public:
    Grid(int row, int col, const T& defaultValue) : row(row), col(col), defaultValue(defaultValue) {
        buffer.resize(row);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                string key = generateKey(j);
                buffer[i][key] = defaultValue;
            }
        }
    }

    ~Grid() {}

    string generateKey(int index) {
        string key;
        while (index >= 0) {
            char letter = 'A' + (index % 26);
            key = letter + key;
            index = index / 26 - 1;
        }
        return key;
    }

    void parseInput(const std::string& input, std::string& alphabets, std::string& numbers) const {
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


    void put(string slot, T item) {
        string indexCol, numbers;
        parseInput(slot, indexCol, numbers);
        int indexRow = stoi(numbers);
        buffer.at(indexRow - 1).at(indexCol) = item;
    }

    T take(string slot) {
        string indexCol, numbers;
        parseInput(slot, indexCol, numbers);
        int indexRow = stoi(numbers);
        T item = buffer.at(indexRow - 1).at(indexCol);
        buffer.at(indexRow - 1).at(indexCol) = defaultValue;
        return item;
    }

    friend ostream& operator<<(ostream& out, const Grid& G) {
        int width = 5;

        out << "     ";
        for (char c = 'A'; c < 'A' + G.getCol(); ++c) {
            out << setw(width) << c << " ";
        }
        out << endl;


        out << "     +";
        for (int i = 0; i < G.getCol(); ++i) {
            out << setw(width) << setfill('-') << "+";
        }
        out << endl;

    
        for (int i = 1; i <= G.getRow(); ++i) {
            out << setw(3) << setfill('0') << i << " |"; // Row number
            for (int j = 0; j < G.getCol(); ++j) {
                string slot = string(1, 'A' + j) + to_string(i);
                T item = G.see(slot);
                out << setw(width) << setfill(' ') << item << " |"; // Cell content
            }
            out << endl;
            out << "     +";
            for (int k = 0; k < G.getCol(); ++k) {
                out << setw(width) << setfill('-') << "+";
            }
            out << endl;
        }
        return out;
    }


    void remove(string slot) {
        string indexCol, numbers;
        parseInput(slot, indexCol, numbers);
        int indexRow = stoi(numbers);
        buffer.at(indexRow - 1).at(indexCol) = defaultValue;
    }

    T see(string slot) const {
        string indexCol, numbers;
        parseInput(slot, indexCol, numbers);
        int indexRow = stoi(numbers);
        T item = buffer.at(indexRow - 1).at(indexCol);
        return item;
    }

    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }
};

#endif
