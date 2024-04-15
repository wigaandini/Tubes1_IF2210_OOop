#include "../Game/Game.hpp"
#include "Slot.hpp"
#include <vector>
#include <random>

Slot::Slot() : Grid<string>(1, 3) {
    prize = {"A", "B", "C"};

}

Slot::~Slot() {}

void Slot::displaySlot()
{
    auto result = this->buffer[0];
    string title = "[ Slot ]";
    int columnWidthWithBorders = 6;
    int totalGridWidth = this->col * columnWidthWithBorders;
    int equalsLength = (totalGridWidth - title.length()) / 2;
    string equalsSide(equalsLength, '=');

    // Header
    cout << "     " << equalsSide << title << equalsSide;
    if ((totalGridWidth - title.length()) % 2 != 0)
    {
        cout << "=";
    }
    cout << "\n";

    // Top border
    cout << "     ";
    for (int j = 0; j < this->col; ++j)
    {
        cout << "+-----";
    }
    cout << "+\n";

    // Grid contents
    for (int i = 0; i < this->row; ++i)
    {
        cout << "     |";
        for (int j = 0; j < this->col; ++j)
        {
            cout << " " << setw(2) << setfill(' ') << *(result[j]) << "  |";
        }
        cout << "\n";

        // Bottom border
        cout << "     ";
        for (int j = 0; j < this->col; ++j)
        {
            cout << "+-----";
        }
        cout << "+\n";
    }
}

pair<int, string> Slot::play()
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);

    for (int i = 0; i < 3; i++)
    {
        int random = dist(gen);
        string slotGrid = prize.at(i) + "01";
        this->put(slotGrid, make_shared<string>(prize[random]));
    }

    cout << endl;
    this->displaySlot();
    cout << endl;
    map<string, int> symbolCounts;
    for (const auto &symbol : this->buffer[0])
    {
        ++symbolCounts[*symbol];
    }

    int guldenBonus = 0;
    string message = "";
    if (symbolCounts["A"] == 3)
    {
        message =  "Selamat! Anda mendapatkan 3 simbol 'A' dan memenangkan 10 gulden!" ;
        guldenBonus = 10;
    }
    else if (symbolCounts["B"] == 3)
    {
        message =  "Selamat! Anda mendapatkan 3 simbol 'B' dan memenangkan 20 gulden!" ;
        guldenBonus = 20;
    }
    else if (symbolCounts["C"] == 3)
    {
        message =  "Selamat! Anda mendapatkan 3 simbol 'C' dan memenangkan 30 gulden!" ;
        guldenBonus = 30;
    }
    else
    {
        message =  "Maaf, Anda belum beruntung kali ini. Coba lagi!" ;
    }

    pair<int, string> result;
    result.first = guldenBonus;
    result.second = message;

    return result;
}