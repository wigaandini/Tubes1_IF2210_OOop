#include "Grid.hpp"
using namespace std;

int main() {
    Grid<string> g(6, 8);

    g.put(1, 'A', "HTL");
    g.put(2, 'A', "XXX");
    g.put(4, 'C', "YYY");
    g.put(4, 'D', "HHH");
    g.put(5, 'C', "HHH");
    g.put(5, 'D', "YYY");

    cout << "Grid awal" << endl << g << endl;

    cout << "Item diambil: " << g.take(4, 'C') << " 4C" << endl;
    cout << "Item dilihat: " << g.see(1, 'A') << " 1A" << endl;
    g.remove(1, 'A');

    cout << "Grid setelah diambil dan dihapus" << endl << g << endl;

    return 0;
}