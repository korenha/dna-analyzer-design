//
// Created by a on 7/6/20.
//
#include <vector>
#include "CommandsManager.h"
using std::map;
CML::ICommand *CommandsManager::getCommand(const std::string &command)
{
    map<std::string,CML::ICommand*>::iterator indexCommand = commandsMap.find(command);
    if(indexCommand != commandsMap.end())
    {
        return indexCommand->second;
    }
    commandsMap.insert(std::pair<std::string,CML::ICommand*>(command, CML::CommandFactory::getCommand(command)));
    return commandsMap.find(command)->second;
}

CommandsManager::~CommandsManager()
{
    map<std::string,CML::ICommand*>::iterator it;
    for ( it = commandsMap.begin(); it != commandsMap.end(); ++it)
    {
        delete it->second;
    }
}
