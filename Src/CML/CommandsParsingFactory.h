#ifndef DNAANALYZERPROJECT_COMMANDSPARSINGFACTORY_H
#define DNAANALYZERPROJECT_COMMANDSPARSINGFACTORY_H

#include <string>
#include "IParams.h"

namespace CML{

class CommandsParsingFactory
{
public:
    static IParams *getParams(const std::string &commandName, const std::string &params);

private:
    CommandsParsingFactory();
    CommandsParsingFactory(const CommandsParsingFactory&);
};

}
#endif //DNAANALYZERPROJECT_COMMANDSPARSINGFACTORY_H
