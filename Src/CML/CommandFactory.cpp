//
// Created by a on 7/6/20.
//

#include "CommandFactory.h"
#include "NewCommand.h"
namespace CML{
    std::vector<std::string> commandsName(CML::CommandFactory::E_Last);
    ICommand *CommandFactory::getCommand(const std::string &commandName)
    {
        unsigned int indexCommand;
        for (indexCommand = 0; indexCommand < commandName.size() &&  commandName != commandsName[indexCommand]; ++indexCommand);
        ECommand command = static_cast<ECommand>(indexCommand);
        switch (command)
        {
            case E_NEW:
                return new NewCommand();
            case E_LOAD:
                break;
            /*....*/
            case E_Last:
                break;
        }
    }
}