//
// Created by a on 7/6/20.
//

#include "ParamsManager.h"
#include "../CLI/CommandsParsingFactory.h"
using std::map;

CLI::IParams *ParamsManager::getParams(const std::string &commandName, const std::vector<std::string> &params){
    map<std::string,CLI::IParams*>::iterator indexCommand = commandParsingMap.find(commandName);
    if(indexCommand != commandParsingMap.end())
    {
        indexCommand->second->set(params);
        return indexCommand->second;
    }
    commandParsingMap.insert(std::pair<std::string,CLI::IParams*>(commandName, CLI::CommandsParsingFactory::getParams(commandName, params)));
    return commandParsingMap.find(commandName)->second;
}

ParamsManager::~ParamsManager() {
    map<std::string,CLI::IParams*>::iterator it;
    for ( it = commandParsingMap.begin(); it != commandParsingMap.end(); ++it)
    {
        delete it->second;
    }

}
