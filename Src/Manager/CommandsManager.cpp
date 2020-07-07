//
// Created by a on 7/6/20.
//
#include <vector>
#include "CommandsManager.h"
using std::map;
CLI::ICommand *CommandsManager::getCommand(const std::string &command)
{
    map<std::string,CLI::ICommand*>::iterator indexCommand = commandsMap.find(command);
    if(indexCommand != commandsMap.end())
    {
        return indexCommand->second;
    }
    commandsMap.insert(std::pair<std::string,CLI::ICommand*>(command, CLI::CommandsFactory::getCommand(command)));
    return commandsMap.find(command)->second;
}

CommandsManager::~CommandsManager()
{
    map<std::string,CLI::ICommand*>::iterator it;
    for ( it = commandsMap.begin(); it != commandsMap.end(); ++it)
    {
        delete it->second;
    }
}
