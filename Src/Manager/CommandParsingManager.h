//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_COMMANDPARSINGMANAGER_H
#define DNAANALYZERPROJECT_COMMANDPARSINGMANAGER_H


#include <string>
#include "../CML/IParams.h"
#include <map>
#include <vector>

class CommandParsingManager {
public:
    CML::IParams* getParams(const std::string& commandName, const std::vector<std::string> &params);
    ~CommandParsingManager();
private:
    std::map<std::string,CML::IParams*> commandParsingMap;
};


#endif //DNAANALYZERPROJECT_COMMANDPARSINGMANAGER_H
