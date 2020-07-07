#ifndef DNAANALYZERPROJECT_COMMANDSPARSINGFACTORY_H
#define DNAANALYZERPROJECT_COMMANDSPARSINGFACTORY_H

#include <string>
#include "Params.h"

namespace CLI{

class CommandsParsingFactory
{
public:
    static Params *getParams(const std::string &commandName, const std::vector<std::string> &params);

private:
    CommandsParsingFactory();
    CommandsParsingFactory(const CommandsParsingFactory&);
};

}
#endif //DNAANALYZERPROJECT_COMMANDSPARSINGFACTORY_H
