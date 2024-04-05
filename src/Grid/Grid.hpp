#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

template<class T>
class Grid{
    private:
        vector<vector<T>> buffer;
        int row;
        int col;
        T defaultValue;
    public:
        Grid(int r, int c, T defaultValue) : row(r), col(c), defaultValue(defaultValue) {
            buffer.resize(row, vector<T>(col));
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    buffer[i][j] = defaultValue;
                }
            }
        }


        ~Grid() {}
        

        void put(int x, char y, const T& val) {
            int colIdx = y - 'A';
            if (x < 0 || x >= row || colIdx < 0 || colIdx >= col) {
                cerr << "Out of bounds\n"; /* Ntar ganti pake exception index */
                return;
            }
            buffer[x-1][colIdx] = val;
        }


        T take(int x, char y) {
            int colIdx = y - 'A'; 
            if (x < 0 || x >= row || colIdx < 0 || colIdx >= col) {
                cerr << "Out of bounds\n";
                return T();
            }
            T val = buffer[x-1][colIdx];
            buffer[x-1][colIdx] = defaultValue;
            return val;
        }


        void remove(int x, char y) {
            int colIdx = y - 'A'; 
            if (x < 0 || x >= row || colIdx < 0 || colIdx >= col) {
                cerr << "Out of bounds\n";
                return;
            }
            buffer[x-1][colIdx] = defaultValue;
        }


        T see(int x, char y) const {
            int colIdx = y - 'A'; 
            if (x < 0 || x >= row || colIdx < 0 || colIdx >= col) {
                cerr << "Out of bounds\n";
                return T();
            }
            return buffer[x-1][colIdx];
        }


        friend ostream& operator<<(ostream& os, const Grid<T>& g) {
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
                    // Cetak isi sel
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


