//
// Created by a on 7/6/20.
//
#include <vector>
#include "CommandsManager.h"
using std::map;
std::map<std::string,CML::ICommand*> commandMap;
CML::ICommand *CommandsManager::getCommand(const std::string &command)
{
    map<std::string,CML::ICommand*>::iterator indexCommand = commandMap.find(command);
    if(indexCommand != commandMap.end())
    {
        return indexCommand->second;
    }
    commandMap.insert(std::pair<std::string,CML::ICommand*>(command,CML::CommandFactory::getCommand(command)));
    return commandMap.find(command)->second;
}
