#ifndef DNAANALYZERPROJECT_COMMANDSPARAMSFACTORY_H
#define DNAANALYZERPROJECT_COMMANDSPARAMSFACTORY_H

#include <string>
#include "Params.h"

namespace CLI{

class CommandsParamsFactory
{
public:
    static Params *getParams(const std::string &commandName, const std::vector<std::string> &params);

private:
    CommandsParamsFactory();
    CommandsParamsFactory(const CommandsParamsFactory&);
};

}
#endif //DNAANALYZERPROJECT_COMMANDSPARAMSFACTORY_H
