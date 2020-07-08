#ifndef DNAANALYZERPROJECT_COMMANDSMANAGER_H
#define DNAANALYZERPROJECT_COMMANDSMANAGER_H


#include <map>
#include <string>
#include "../CLI/ICommand.h"
#include "../CLI/CommandsFactory.h"
class CommandsManager
{
public:
    CLI::ICommand *getCommand(const std::string &command, const IReader *const reader, const IWriter *const writer);
    ~CommandsManager();
private:
    std::map<std::string,CLI::ICommand*> commandsMap;

};


#endif //DNAANALYZERPROJECT_COMMANDSMANAGER_H
