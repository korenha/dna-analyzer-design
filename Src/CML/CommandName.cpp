//
// Created by a on 7/6/20.
//

#include "CommandName.h"
namespace CML{
    std::string commandsName[CommandName::E_Last+1] = {"new"};

    CommandName::ECommand CommandName::getECommand(const std::string &commandName)
    {
        unsigned int indexCommand;
        for (indexCommand = 0; indexCommand < E_Last+1 &&  commandName != commandsName[indexCommand]; ++indexCommand);
        return (ECommand)indexCommand;

    }
}