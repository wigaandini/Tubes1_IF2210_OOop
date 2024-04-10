#include "Grid.hpp"

template <class T>
void Grid<T>::parseInput(string s, int &intt, char &charr) const
{
    charr = s[0];
    intt = stoi(s.substr(1));
}

template <class T>
void Grid<T>::parseInput(string s, int &row, int &col) const
{
    char colTemp = s[0];
    row = stoi(s.substr(1));
    col = colTemp - 'A';
}

template <class T>
Grid<T>::Grid(int r, int c, T defaultValue) : row(r), col(c), emptySlot(r * c), defaultValue(defaultValue)
{
    buffer.resize(row, vector<shared_ptr<T>>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            buffer[i][j] = nullptr;
        }
    }
}

template <class T>
Grid<T>::Grid(int r, int c) : row(r), col(c), emptySlot(r * c)
{
    buffer.resize(row, vector<shared_ptr<T>>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            buffer[i][j] = nullptr;
        }
    }
}

template <class T>
Grid<T>::~Grid()
{
}

template <class T>
int Grid<T>::getRow() const
{
    return this->row;
}

template <class T>
int Grid<T>::getcol() const
{
    return this->col;
}

template <class T>
bool Grid<T>::isEmpty()
{
    return emptySlot == row * col;
}

template <class T>
int Grid<T>::countEmpty() const
{
    return emptySlot;
}

template <class T>
shared_ptr<T> Grid<T>::see(int i, int j) const
{
    return buffer[i][j];
}

template <class T>
void Grid<T>::remove(int i, int j)
{
    buffer[i][j] = nullptr;
    emptySlot++;
}

template <class T>
void Grid<T>::put(string slot, const shared_ptr<T> val)
{
    if (emptySlot == 0)
    {
        throw GridFullException();
    }
    int x;
    char y;
    parseInput(slot, x, y);
    int colIdx = y - 'A';
    if (x <= 0 || x >= row || colIdx < 0 || colIdx >= col)
    {
        throw IndexOutOfBoundException();
    }
    if (buffer[x - 1][colIdx] == nullptr)
    {
        buffer[x - 1][colIdx] = val;
        emptySlot--;
    }
    else
    {
        throw SlotOccupiedException();
    }
}

template <class T>
shared_ptr<T> Grid<T>::take(string slot)
{
    if (emptySlot == row * col)
    {
        throw GridEmptyException();
    }
    int x;
    char y;
    parseInput(slot, x, y);
    int colIdx = y - 'A';
    if (x <= 0 || x >= row || colIdx < 0 || colIdx >= col)
    {
        throw IndexOutOfBoundException();
    }
    auto val = buffer[x - 1][colIdx];
    if (val == nullptr)
    {
        throw SlotEmptyException();
    }
    buffer[x - 1][colIdx] = nullptr;
    emptySlot++;
    return val;
}

template <class T>
void Grid<T>::remove(string slot)
{
    if (emptySlot == row * col)
    {
        throw GridEmptyException();
    }
    int x;
    char y;
    parseInput(slot, x, y);
    int colIdx = y - 'A';
    if (x <= 0 || x >= row || colIdx < 0 || colIdx >= col)
    {
        throw IndexOutOfBoundException();
    }
    if (buffer[x - 1][colIdx] == nullptr)
    {
        throw SlotEmptyException();
    }
    buffer[x - 1][colIdx] = nullptr;
    emptySlot++;
}

template <class T>
T &Grid<T>::see(string slot)
{
    int x;
    char y;
    parseInput(slot, x, y);
    int colIdx = y - 'A';
    if (x <= 0 || x >= row || colIdx < 0 || colIdx >= col)
    {
        throw IndexOutOfBoundException();
    }
    if (buffer[x - 1][colIdx] == nullptr)
    {
        throw SlotEmptyException();
    }
    return *(buffer[x - 1][colIdx]);
}

template <class T>
ostream &operator<<(ostream &os, const Grid<T> &g)
{
    // Cetak header kolom
    os << "    ";
    for (int j = 0; j < g.col; ++j)
    {
        os << setw(5) << (char)('A' + j) << " ";
    }
    os << "\n";

    // Cetak garis pemisah
    os << "     ";
    for (int j = 0; j < g.col; ++j)
    {
        os << "+-----";
    }
    os << "+\n";

    // Cetak isi grid
    for (int i = 0; i < g.row; ++i)
    {
        // Cetak nomor baris
        os << setw(2) << setfill('0') << (i + 1) << "   |";
        for (int j = 0; j < g.col; ++j)
        {
            // Cetak isi selpe
            if (g.buffer[i][j] != nullptr)
            {
                os << " " << setw(3) << setfill(' ') << *g.buffer[i][j] << " |";
            }
            else
            {
                os << " " << setw(3) << setfill(' ') << "   " << " |";
            }
        }
        os << "\n";

        // Cetak garis pemisah setelah setiap baris
        os << "     ";
        for (int j = 0; j < g.col; ++j)
        {
            os << "+-----";
        }
        os << "+\n";
    }
    return os;
}
