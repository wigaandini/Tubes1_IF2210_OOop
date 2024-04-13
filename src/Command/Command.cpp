#include "Command.hpp"
#include "../Mayor/Mayor.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Farmer/Farmer.hpp"
#include "../Game/Game.hpp"
#include <algorithm>

Command::Command()
{
    this->playerCommand = {"CETAK_PENYIMPANAN", "MAKAN", "SIMPAN", "JUAL", "BELI", "MUAT"};
    this->mayorCommand = {"TAMBAH_PEMAIN", "PUNGUT_PAJAK", "BANGUN_BANGUNAN", "TAMBAH_PEMAIN"};
    this->farmerCommand = {"TANAM", "CETAK_LADANG", "PANEN"};
    this->breederCommand = {"TERNAK", "CETAK_PETERNAKAN", "KASIH_MAKAN", "PANEN"};
}

Command::~Command()
{
}

pair<vector<string>, string> Command::allCommandFor(shared_ptr<Player> &player)
{
    vector<string> commands(playerCommand);

    pair<vector<string>, string> data;

    if (shared_ptr<Mayor> mayor = dynamic_pointer_cast<Mayor>(Game::getCurrentPlayer()))
    {
        commands.insert(commands.end(), mayorCommand.begin(), mayorCommand.end());
        data.second = "Walikota";
    }
    else if (shared_ptr<Farmer> farmer = dynamic_pointer_cast<Farmer>(Game::getCurrentPlayer()))
    {
        commands.insert(commands.end(), farmerCommand.begin(), farmerCommand.end());
        data.second = "Petani";
    }
    else
    {
        commands.insert(commands.end(), breederCommand.begin(), breederCommand.end());
        data.second = "Peternak";
    }
    // cout << "command" << playerCommand.size() << endl;
    data.first = commands;

    return data;
}

bool Command::checkCommand(const string &command)
{
    vector<string> commands(allCommandFor(Game::getCurrentPlayer()).first);

    auto it = find(commands.begin(), commands.end(), command);

    if (it == commands.end())
    {
        return false;
    }

    return true;
}

void Command::handleCommand(const string &command)
{
    if (command == "BELI")
    {
        Game::getStore().handleCustomerBuy();
    }
    else if (command == "JUAL")
    {
        Game::getStore().handleCustomerSell();
    }
    else if (command == "MAKAN")
    {
        Game::getCurrentPlayer()->eat();
    }
    else if (command == "CETAK_PENYIMPANAN")
    {
        Game::getCurrentPlayer()->getInventory().displayStorage(true);
    }
    else if (command == "SIMPAN") 
    { 
        
    }
    else if (shared_ptr<Mayor> mayor = dynamic_pointer_cast<Mayor>(Game::getCurrentPlayer()))
    {
        if (command == "PUNGUT_PAJAK")
        {
            mayor->taxCollection();
        }
        else if (command == "TAMBAH_PEMAIN")
        {
            mayor->addPlayer();
        }
        else if (command == "BANGUN_BANGUNAN")
        {
            mayor->buildBuilding();
        }
    }
    else if (shared_ptr<Farmer> farmer = dynamic_pointer_cast<Farmer>(Game::getCurrentPlayer()))
    {
        if (command == "TANAM")
        {
            farmer->plant();
        }
        else if (command == "CETAK_LADANG")
        {
            farmer->getFarm().displayStorage(true);
        }
        else if (command == "PANEN")
        {
            farmer->harvest();
        }
    }
    else if (shared_ptr<Breeder> breeder = dynamic_pointer_cast<Breeder>(Game::getCurrentPlayer()))
    {
        if (command == "TERNAK")
        {
            breeder->cattle();
        }
        else if (command == "CETAK_PETERNAKAN")
        {
            breeder->getRanch().displayStorage(true);
        }
        else if (command == "KASIH_MAKAN")
        {
            breeder->feedAnimal();
        }
        else if (command == "PANEN")
        {
            breeder->harvest();
        }
    }
}

void Command::printCommand(shared_ptr<Player> &player)
{
    pair<vector<string>, string> data = allCommandFor(player);
    // cout << allCommandFor(player).first.size() << endl;
    vector<string> commands(data.first);
    commands.push_back("NEXT");

    cout << "Role pemain adalah " << data.second << endl;
    cout << "Command yang tersedia: " << endl;
    for (unsigned int i = 0; i < commands.size(); i++)
    {
        cout << i + 1 << ". " << commands[i] << endl;
    }

    cout << endl;
}
