#ifndef _COMMAND_HANDLER_HPP_
#define _COMMAND_HANDLER_HPP_

#include <string>
#include <vector>

using namespace std;

class Command
{
private:
    bool checkCommandBreeder(const string&);
    bool checkCommandMayor(const string&);
    bool checkCommandFarmer(const string&);
    
    
public:
    Command();
    ~Command();
    bool checkCommand(const string&);
    void handleCommand(const string&);
};




#endif