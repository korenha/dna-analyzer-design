#ifndef DNAANALYZERPROJECT_COMMANDSMANAGER_H
#define DNAANALYZERPROJECT_COMMANDSMANAGER_H


#include <map>
#include <string>
#include "../CML/ICommand.h"
#include "../CML/CommandFactory.h"
class CommandsManager
{
public:
    CML::ICommand* getCommand(const std::string &command);
    //add dtor
private:
    static std::map<std::string,CML::ICommand*> commandParsingMap;

};


#endif //DNAANALYZERPROJECT_COMMANDSMANAGER_H
