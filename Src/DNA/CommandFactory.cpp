//
// Created by a on 7/6/20.
//

#include "CommandFactory.h"
#include "NewCommand.h"
#include "CommandName.h"
namespace CML{
    ICommand *CommandFactory::getCommand(const std::string &commandName)
    {

        switch (CommandName::getECommand(commandName))
        {
            case CommandName::E_NEW:
                return new NewCommand();
            case CommandName::E_LOAD:
                break;
            /*....*/
            case CommandName::E_Last:
                break;
            default:
                return NULL;
        }
        return NULL;
    }
}