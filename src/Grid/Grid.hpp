#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

template<class T>
class Grid{
    protected:
        vector<vector<T>> buffer;
        int row;
        int col;
        int emptySlot;
        T defaultValue;
        void parseInput(string s, int& intt,char& charr) const{
            charr = s[0];
            intt = stoi(s.substr(1));
        }
    public:
        Grid(int r, int c, T defaultValue) : row(r), col(c), emptySlot(r*c), defaultValue(defaultValue) {
            buffer.resize(row, vector<T>(col));
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    buffer[i][j] = defaultValue;
                }
            }
        }

        ~Grid() {}

        bool isEmpty(){
            return emptySlot == row*col;
        }

        int countEmpty() const{
            return emptySlot;
        }

        void put(string slot, const T& val) {
            int x; char y;
            parseInput(slot, x, y);
            int colIdx = y - 'A';
            if (x < 0 || x >= row || colIdx < 0 || colIdx >= col) {
                cerr << "Out of bounds\n"; /* Ntar ganti pake exception index */
                return;
            }
            buffer[x-1][colIdx] = val;
            emptySlot--;
        }


        T take(string slot) {
            int x; char y;
            parseInput(slot, x, y);
            int colIdx = y - 'A'; 
            if (x < 0 || x >= row || colIdx < 0 || colIdx >= col) {
                cerr << "Out of bounds\n";
                return T();
            }
            T val = buffer[x-1][colIdx];
            buffer[x-1][colIdx] = defaultValue;
            emptySlot++;
            return val;
        }


        void remove(string slot) {
            int x; char y;
            parseInput(slot, x, y);
            int colIdx = y - 'A'; 
            if (x < 0 || x >= row || colIdx < 0 || colIdx >= col) {
                cerr << "Out of bounds\n";
                return;
            }
            buffer[x-1][colIdx] = defaultValue;
            emptySlot++;
        }


        T see(string slot) const {
            int x; char y;
            parseInput(slot, x, y);
            int colIdx = y - 'A'; 
            if (x < 0 || x >= row || colIdx < 0 || colIdx >= col) {
                cerr << "Out of bounds\n";
                return T();
            }
            return buffer[x-1][colIdx];
        }


        friend ostream& operator<<(ostream& os, const Grid& g) {
            // Cetak header kolom
            os << "    ";
            for (int j = 0; j < g.col; ++j) {
                os << setw(5) << static_cast<char>('A' + j) << " ";
            }
            os << "\n";

            // Cetak garis pemisah
            os << "     ";
            for (int j = 0; j < g.col; ++j) {
                os << "+-----";
            }
            os << "+\n";

            // Cetak isi grid
            for (int i = 0; i < g.row; ++i) {
                // Cetak nomor baris
                os << setw(2) << setfill('0') << (i + 1) << "   |";
                for (int j = 0; j < g.col; ++j) {
                    // Cetak isi selpe
                    os << " " << setw(3) << setfill(' ') << g.buffer[i][j] << " |";
                }
                os << "\n";

                // Cetak garis pemisah setelah setiap baris
                os << "     ";
                for (int j = 0; j < g.col; ++j) {
                    os << "+-----";
                }
                os << "+\n";
            }
            return os;
        }

};


#endif


