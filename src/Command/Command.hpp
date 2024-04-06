#ifndef _COMMAND_HANDLER_HPP_
#define _COMMAND_HANDLER_HPP_

#include <string>
#include <vector>

using namespace std;

class Command
{
private:
    vector<string> playerCommand;
    vector<string> mayorCommand;
    vector<string> breederCommand;
    vector<string> farmerCommand;

    
public:
    Command();
    ~Command();
    bool checkCommand(const string&);
    void handleCommand(const string&);
};




#endif