#include "CommandFactory.h"
#include "CommandName.h"
#include "NewCommand.h"
namespace CLI{

    ICommand *CommandFactory::getCommand(const std::string &command)
    {
        switch (CommandName::getECommand(command))
        {
            case CommandName::E_NEW:
                return (ICommand*)(new NewCommand());
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
