#include "../Game/Game.hpp"
#include "Slot.hpp"
#include <vector>

Slot::Slot() : Grid<string>(1, 3){}

Slot::~Slot(){}

void Slot::displaySlot(vector<string> result) {
    string title = "[ Slot ]";
    int columnWidthWithBorders = 6;
    int totalGridWidth = this->col * columnWidthWithBorders;
    int equalsLength = (totalGridWidth - title.length()) / 2;
    string equalsSide(equalsLength, '=');
    
    // Header
    cout << "     " << equalsSide << title << equalsSide;
    if ((totalGridWidth - title.length()) % 2 != 0) {
        cout << "=";
    }
    cout << "\n";
    
    // Top border
    cout << "     ";
    for (int j = 0; j < this->col; ++j) {
        cout << "+-----";
    }
    cout << "+\n";
    
    // Grid contents
    for (int i = 0; i < this->row; ++i)
    {
        cout << "     |";
        for (int j = 0; j < this->col; ++j)
        {   
            cout << " " << setw(2) << setfill(' ') << result[j] << "  |";
        }
        cout << "\n";
        
        // Bottom border
        cout << "     ";
        for (int j = 0; j < this->col; ++j) {
            cout << "+-----";
        }
        cout << "+\n";
    }
}