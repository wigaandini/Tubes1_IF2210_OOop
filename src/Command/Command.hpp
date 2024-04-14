#ifndef _COMMAND_HANDLER_HPP_
#define _COMMAND_HANDLER_HPP_

#include <string>
#include <vector>
#include <memory>
#include "../Player/Player.hpp"

using namespace std;

class Command
{
private:
    vector<string> playerCommand;
    vector<string> mayorCommand;
    vector<string> breederCommand;
    vector<string> farmerCommand;
    pair<vector<string>, string> allCommandFor(shared_ptr<Player>&);

    
public:
    Command();
    ~Command();
    // bool checkCommand(const string&);
    void handleCommand(const string&);
    void printCommand(shared_ptr<Player>&);
};




#endif