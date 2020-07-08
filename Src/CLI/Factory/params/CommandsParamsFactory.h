#ifndef DNAANALYZERPROJECT_COMMANDSNAMEFACTORY_H
#define DNAANALYZERPROJECT_COMMANDSNAMEFACTORY_H

#include "../../CommandsParams/Params.h"

namespace CLI{

    class CommandsParamsFactory
    {
    public:
        static Params* getParams(const std::string &commandName, const std::vector<std::string> &params);
    private:
        CommandsParamsFactory();
        CommandsParamsFactory(const CommandsParamsFactory&);
    };

}
#endif //DNAANALYZERPROJECT_COMMANDSNAMEFACTORY_H
