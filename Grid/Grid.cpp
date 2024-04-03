#include "Grid.hpp"

template <class T>
Grid<T>::Grid() {
    this->col = 0;
    this->row = 0;
}

template <class T>
Grid<T>::Grid(int col, int row) {
    this->col = col;
    this->row = row;
}

template <class T>
Grid<T>::Grid(const Grid &grid) {
    this->col = grid.col;
    this->row = grid.row;
    this->buffer = grid.buffer;
}

template <class T>
Grid<T>::~Grid() {
    buffer.clear();
}

template <class T>
void Grid<T>::put(string key, T value) {
    map<string, T> temp;
    temp[key] = value;
    buffer.push_back(temp);
}

template <class T>
T Grid<T>::get(string key) {
    for (int i = 0; i < buffer.size(); i++) {
        if (buffer[i].find(key) != buffer[i].end()) {
            return buffer[i][key];
        }
    }
    return NULL;
}

template <class T>
void Grid<T>::remove(string key) {
    for (int i = 0; i < buffer.size(); i++) {
        if (buffer[i].find(key) != buffer[i].end()) {
            buffer[i].erase(key);
        }
    }
}

template <class T>
T Grid<T>::see(string key) {
    for (int i = 0; i < buffer.size(); i++) {
        if (buffer[i].find(key) != buffer[i].end()) {
            return buffer[i][key];
        }
    }
    return NULL;
}

template <class T>
ostream& operator<<(ostream &os, Grid<T> &grid) {
    os << "   ";
    for (char c = 'A'; c < 'A' + grid.col; ++c) {
        os << setw(5) << c;
    }
    os << endl;

    os << "   ";
    for (int i = 0; i < grid.col; ++i) {
        os << "+-----";
    }
    os << "+" << endl;

    for (int i = 0; i < grid.row; ++i) {
        os << setw(3) << i + 1 << " ";
        for (int j = 0; j < grid.col; ++j) {
            os << "| ";
            string key = "";
            key += ('A' + j);
            key += to_string(i + 1);
            T value = grid.get(key);
            if (value != NULL) {
                os << setw(3) << value;
            } else {
                os << setw(3) << " ";
            }
            os << " ";
        }
        os << "|" << endl;

        os << "   ";
        for (int k = 0; k < grid.col; ++k) {
            os << "+-----";
        }
        os << "+" << endl;
    }

    return os;
}