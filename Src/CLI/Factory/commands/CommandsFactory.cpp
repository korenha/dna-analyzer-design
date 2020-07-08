#include "CommandsFactory.h"
#include "../commandsName/CommandName.h"
#include "../../Commands/creationCommands/new/NewCommand.h"
#include "../../Commands/creationCommands/load/LoadCommand.h"
#include "../../Commands/creationCommands/dup/DupCommand.h"
#include "../../Commands/management/save/SaveCommand.h"
#include "../../Commands/doNothing/DoNothing.h"
#include "../../Commands/controlCommand/quit/QuitCommand.h"
#include "../../Commands/manipulation/slice/SliceCommand.h"
#include "../../Commands/manipulation/replace/ReplaceCommand.h"
#include "../../Commands/manipulation/concat/ConcatCommand.h"
#include "../../Commands/manipulation/pair/PairCommand.h"

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
            case CommandName::E_SLICE:
                return (ICommand*)(new SliceCommand());
            case CommandName::E_REPLACE:
                return (ICommand*)(new ReplaceCommand());
            case CommandName::E_CONCAT:
                return (ICommand*)(new ConcatCommand());
            case CommandName::E_PAIR:
                return (ICommand*)(new PairCommand());
            case CommandName::E_SAVE:
                return (ICommand*)(new SaveCommand());
                /*....*/
            case CommandName::E_QUIT:
                return (ICommand*)(new QuitCommand(reader,writer));
            default:
                return NULL;
        }
    }
}
