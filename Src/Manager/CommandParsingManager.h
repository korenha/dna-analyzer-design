//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_COMMANDPARSINGMANAGER_H
#define DNAANALYZERPROJECT_COMMANDPARSINGMANAGER_H


#include <string>
#include "../CML/IParams.h"
#include <map>
class CommandParsingManager {
public:
    CML::IParams* getCommand(const std::string& commandName,const std::string &command);
    //add dtor
private:
    static std::map<std::string,CML::IParams*> commandParsingMap;
};


#endif //DNAANALYZERPROJECT_COMMANDPARSINGMANAGER_H
