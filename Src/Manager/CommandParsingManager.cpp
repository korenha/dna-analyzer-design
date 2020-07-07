//
// Created by a on 7/6/20.
//

#include "CommandParsingManager.h"
#include "../CML/CommandsParsingFactory.h"
using std::map;

CML::IParams *CommandParsingManager::getParams(const std::string &commandName, const std::vector<std::string> &params){
    map<std::string,CML::IParams*>::iterator indexCommand = commandParsingMap.find(commandName);
    if(indexCommand != commandParsingMap.end())
    {
        return indexCommand->second;
    }
    commandParsingMap.insert(std::pair<std::string,CML::IParams*>(commandName, CML::CommandsParsingFactory::getParams(commandName, params)));
    return commandParsingMap.find(commandName)->second;
}

CommandParsingManager::~CommandParsingManager() {
    map<std::string,CML::IParams*>::iterator it;
    for ( it = commandParsingMap.begin(); it != commandParsingMap.end(); ++it)
    {
        delete it->second;
    }

}
