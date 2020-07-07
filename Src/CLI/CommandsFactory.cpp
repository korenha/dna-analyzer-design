#include "CommandsFactory.h"
#include "CommandName.h"
#include "Commands/NewCommand.h"
#include "Commands/LoadCommand.h"

namespace CLI{

    ICommand *CommandsFactory::getCommand(const std::string &command)
    {
        switch (CommandName::getECommand(command))
        {
            case CommandName::E_NEW:
                return (ICommand*)(new NewCommand());
            case CommandName::E_LOAD:
                return (ICommand*)(new LoadCommand());
                /*....*/
            case CommandName::E_Last:
                break;
            default:
                return NULL;
        }
        return NULL;
    }
}
