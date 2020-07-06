//
// Created by a on 7/6/20.
//

#include "CommandName.h"
namespace CML{
    std::string commandsName[CommandName::E_Last] = {};

    CommandName::ECommand CommandName::getECommand(const std::string &commandName)
    {
        unsigned int indexCommand;
        for (indexCommand = 0; indexCommand < E_Last &&  commandName != commandsName[indexCommand]; ++indexCommand);
        return (ECommand)indexCommand;

    }
}