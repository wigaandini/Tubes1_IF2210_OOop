#include "Command.hpp"
#include "../Mayor/Mayor.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Farmer/Farmer.hpp"
#include "../Game/Game.hpp"
#include <algorithm>

Command::Command()
{
}

Command::~Command()
{
}

bool Command::checkCommand(const string &command)
{
    if (const Mayor *mayor = dynamic_cast<const Mayor *>(&Game::getCurrentPlayer()))
    {
        cout << mayor << "  ini tes" << endl;
        return checkCommandMayor(command);
    }
    // else if (const Farmer *farmer = dynamic_cast<const Farmer *>(&Game::getCurrentPlayer()))
    // {
    // }
    // else
    // {
    // }

    return false;
}

bool Command::checkCommandMayor(const string &command)
{
    vector<string> mayorCommand = {"BELI", "JUAL"};

    auto it = find(mayorCommand.begin(), mayorCommand.end(), command);

    if (it == mayorCommand.end())
    {
        return false;
    }

    return true;
}

void Command::handleCommand(const string& command){
    if (command.compare("BELI") == 0){
        Game::getCurrentPlayer().buy();
    }
}