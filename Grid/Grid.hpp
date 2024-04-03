#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<class T>
class Grid {
    private:
        vector<map<string, T>> buffer;
        int row;
        int col;
    public:
        Grid() {
            row = 0;
            col = 0;
        }

        Grid(int row, int col) {
            this->row = row;
            this->col = col;
            buffer.resize(row);
            for (int i = 0; i < row; i++) {
                buffer[i].clear();
            }
        }

        Grid(const Grid& G) {
            row = G.row;
            col = G.col;
            buffer = G.buffer;
        }

        ~Grid() {
            buffer.clear();
        }

        void put(string slot, T item) {
            int r = slot[1] - '1';
            int c = slot[0] - 'A';
            buffer[r][slot] = item;
        }

        T take(string slot) {
            int r = slot[1] - '1';
            int c = slot[0] - 'A';
            return buffer[r][slot];
        }

friend ostream& operator<<(ostream& out, const Grid& G) {
    out << "     ";
    for (int i = 0; i < G.col; i++) {
        out << "    " << (char)('A' + i) << "   ";
    }
    out << endl;
    out << "     +";
    for (int i = 0; i < G.col; i++) {
        out << "-----+";
    }
    out << endl;
    for (int i = 0; i < G.row; i++) {
        out << "  " << i + 1;
        if (i + 1 < 10) {
            out << " ";
        }
        out << " |";
        for (int j = 0; j < G.col; j++) {
            string slot = string(1, 'A' + j) + to_string(i + 1);
            T item = G.see(slot);
            if (G.buffer[i].count(slot) > 0) {
                out.width(5);
                out << item << " |";
            } else {
                out << "     |";
            }
        }
        out << endl;
        out << "     +";
        for (int j = 0; j < G.col; j++) {
            out << "-----+";
        }
        out << endl;
    }
    return out;
}


        void remove(string slot) {
            int r = slot[1] - '1';
            int c = slot[0] - 'A';
            buffer[r].erase(slot);
        }

        T see(string slot) const {
            int r = slot[1] - '1';
            int c = slot[0] - 'A';
            auto it = buffer[r].find(slot);
            if (it != buffer[r].end()) {
                return it->second;
            }
            return T();
        }

};

#endif
