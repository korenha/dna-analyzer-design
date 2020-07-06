#ifndef DNAANALYZERPROJECT_COMMANDSPARSINGFACTORY_H
#define DNAANALYZERPROJECT_COMMANDSPARSINGFACTORY_H

#include <string>
#include "IParams.h"

namespace CML{

class CommandsParsingFactory
{
public:
    enum EPCommand{
        E_NEW,
        E_LOAD,
        //....
                E_Last
    };
public:
    static IParams* getParams(const std::string &params);

private:
    CommandsParsingFactory();
    CommandsParsingFactory(const CommandsParsingFactory&);
};

}
#endif //DNAANALYZERPROJECT_COMMANDSPARSINGFACTORY_H
