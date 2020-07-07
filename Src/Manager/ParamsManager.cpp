//
// Created by a on 7/6/20.
//

#include "ParamsManager.h"
#include "../CLI/CommandsParsingFactory.h"
using std::map;

CLI::Params *ParamsManager::getParams(const std::string &commandName, const std::vector<std::string> &params){
    map<std::string,CLI::Params*>::iterator indexCommand = commandMap.find(commandName);
    if(indexCommand != commandMap.end())
    {
        indexCommand->second->set(params);
        return indexCommand->second;
    }
    commandMap.insert(std::pair<std::string,CLI::Params*>(commandName, CLI::CommandsParsingFactory::getParams(commandName, params)));
    return commandMap.find(commandName)->second;
}

ParamsManager::~ParamsManager() {
    map<std::string,CLI::Params*>::iterator it;
    for ( it = commandMap.begin(); it != commandMap.end(); ++it)
    {
        delete it->second;
    }

}