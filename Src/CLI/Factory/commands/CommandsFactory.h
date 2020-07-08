//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_COMMANDSFACTORY_H
#define DNAANALYZERPROJECT_COMMANDSFACTORY_H


#include <string>
#include "../../Commands/ICommand.h"
#include "../../../Reader/IReader.h"
#include "../../../Writer/IWriter.h"

namespace CLI{

    class CommandsFactory
    {
    public:
        static ICommand *
        getCommand(const std::string &command, const IReader *const reader, const IWriter *const writer);

    private:
        CommandsFactory();
        CommandsFactory(const CommandsFactory&);

    };

}


#endif //DNAANALYZERPROJECT_COMMANDSFACTORY_H
