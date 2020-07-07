#ifndef DNAANALYZERPROJECT_PARAMSMANAGER_H
#define DNAANALYZERPROJECT_PARAMSMANAGER_H

#include <string>
#include "../CLI/Params.h"
#include <map>
#include <vector>

class ParamsManager {
public:
    CLI::Params* getParams(const std::string& commandName, const std::vector<std::string> &params);
    ~ParamsManager();
private:
    std::map<std::string,CLI::Params*> commandMap;
};

#endif //DNAANALYZERPROJECT_PARAMSMANAGER_H
