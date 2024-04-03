#include "Grid.hpp"

int main() {
    Grid<string> grid(8, 7);
    grid.put("A1", "COW");
    grid.put("B1", "COW");
    grid.put("A2", "COW");
    grid.put("B2", "COW");
    grid.put("E3", "SNK");
    grid.put("G5", "CHK");
    grid.put("H6", "CHK");
    grid.put("A7", "SNK");

    cout << grid.see("A1") << endl;  // Outputs: COW
    cout << grid.see("E3") << endl;  // Outputs: SNK
    cout << grid.see("H8") << endl;  // Outputs: (blank)

    cout << grid;

    return 0;
}