//
// Created by a on 7/6/20.
//
#include <vector>
#include "CommandsManager.h"
using std::map;
CML::ICommand *CommandsManager::getCommand(const std::string &command)
{
    map<std::string,CML::ICommand*>::iterator indexCommand = commandParsingMap.find(command);
    if(indexCommand != commandParsingMap.end())
    {
        return indexCommand->second;
    }
    commandParsingMap.insert(std::pair<std::string,CML::ICommand*>(command, CML::CommandFactory::getCommand(command)));
    return commandParsingMap.find(command)->second;
}
