// #include <iostream>
// #include "Grid.hpp"
// using namespace std;

// int main() {
//     // Create a grid of integers with 5 rows and 5 columns
//     Grid<int> grid(6, 6);

//     // Put some items in the grid
//     grid.put("A1", 10);
//     grid.put("B2", 20);
//     grid.put("D4", 30);
//     grid.put("E5", 40);
//     grid.put("F6", 50);
//     grid.put("C3", 60);
//     grid.put("A6", 70);



//     // Output the grid
//     cout << grid << endl;

//     // Take an item from the grid
//     int item = grid.take("A1");
//     cout << "Item taken from A1: " << item << endl;

//     // Remove an item from the grid
//     grid.remove("B2");
//     cout << "After removing B2:" << endl;
//     cout << grid << endl;

//     // See an item in the grid
//     int seenItem = grid.see("D4");
//     cout << "Item seen in D4: " << seenItem << endl;

//     return 0;
// }


#include <iostream>
#include "Grid.hpp"

int main() {
    // Create a grid of integers with 5 rows and 5 columns, default value 0
    Grid<int> grid(5, 5, 0);

    // Put some items in the grid
    grid.put("A1", 10);
    grid.put("B2", 20);
    grid.put("D4", 30);

    // Output the grid
    std::cout << "Initial Grid:" << std::endl;
    std::cout << grid << std::endl;

    // Take an item from the grid
    int item = grid.take("A1");
    std::cout << "Item taken from A1: " << item << std::endl;

    // Remove an item from the grid
    grid.remove("B2");
    std::cout << "After removing B2:" << std::endl;
    std::cout << grid << std::endl;

    // See an item in the grid
    int seenItem = grid.see("D4");
    std::cout << "Item seen in D4: " << seenItem << std::endl;

    return 0;
}
