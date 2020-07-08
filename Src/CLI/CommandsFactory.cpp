#include "CommandsFactory.h"
#include "CommandName.h"
#include "Commands/NewCommand.h"
#include "Commands/LoadCommand.h"
#include "Commands/DupCommand.h"
#include "Commands/management/SaveCommand.h"
#include "Commands/DoNothing.h"
#include "Commands/controlCommand/QuitCommand.h"

namespace CLI{

    ICommand *CommandsFactory::getCommand(const std::string &command, const IReader *const reader,
                                          const IWriter *const writer)
    {
        switch (CommandName::getECommand(command))
        {
            case CommandName::E_DO_NOTHING:
                return (ICommand*)(new DoNothing());
            case CommandName::E_NEW:
                return (ICommand*)(new NewCommand());
            case CommandName::E_LOAD:
                return (ICommand*)(new LoadCommand());
            case CommandName::E_DUP:
                return (ICommand*)(new DupCommand());
            case CommandName::E_SAVE:
                return (ICommand*)(new SaveCommand());
                /*....*/
            case CommandName::E_QUIT:
                return (ICommand*)(new QuitCommand(reader,writer));
            case CommandName::E_Last:
                break;
        }
        return NULL;
    }
}
