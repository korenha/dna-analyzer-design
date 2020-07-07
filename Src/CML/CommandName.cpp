//
// Created by a on 7/6/20.
//

#include <stdexcept>
#include "CommandName.h"
namespace CML{
    std::string commandsName[CommandName::E_Last+1] = {"new"};

    CommandName::ECommand CommandName::getECommand(const std::string &commandName)
    {
        unsigned int indexCommand;
        for (indexCommand = 0; indexCommand < E_Last+1 &&  commandName != commandsName[indexCommand]; ++indexCommand);
        if(indexCommand == E_Last+1)
        {
            throw std::invalid_argument(std::string("Not found the command "+commandName));
        }
        return (ECommand)indexCommand;
    }
}