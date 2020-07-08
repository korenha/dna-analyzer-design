//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_COMMANDSFACTORY_H
#define DNAANALYZERPROJECT_COMMANDSFACTORY_H


#include <string>
#include "ICommand.h"
namespace CLI{

    class CommandsFactory
    {
    public:
        static ICommand* getCommand(const std::string &command);

    private:
        CommandsFactory();
        CommandsFactory(const CommandsFactory&);

    };

}


#endif //DNAANALYZERPROJECT_COMMANDSFACTORY_H
