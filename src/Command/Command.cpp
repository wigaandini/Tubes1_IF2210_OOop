#include "Command.hpp"
#include "../Mayor/Mayor.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Farmer/Farmer.hpp"
#include "../Game/Game.hpp"
#include <algorithm>

Command::Command()
{
    vector<string> playerCommand = { "NEXT", "CETAK_PENYIMPANAN", "MAKAN","SIMPAN", "JUAL", "BELI" };
    vector<string> mayorCommand = {"TAMBAH_PEMAIN"};
    vector<string> farmerCommand = {"TANAM"};
    vector<string> breederCommand = {"TERNAK"};


}

Command::~Command()
{
}

bool Command::checkCommand(const string &command)
{
    vector<string> commands(playerCommand);

    if (const Mayor *mayor = dynamic_cast<const Mayor *>(&Game::getCurrentPlayer()))
    {
        commands.insert(commands.end(), mayorCommand.begin(), mayorCommand.end());
    }
    else if (const Farmer *farmer = dynamic_cast<const Farmer *>(&Game::getCurrentPlayer()))
    {
        commands.insert(commands.end(), farmerCommand.begin(), farmerCommand.end());


    }
    else
    {
        commands.insert(commands.end(), breederCommand.begin(), breederCommand.end());

    }

    auto it = find(commands.begin(), commands.end(), command);

    if (it == commands.end())
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