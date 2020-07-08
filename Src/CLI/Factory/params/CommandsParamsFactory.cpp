//
// Created by a on 7/6/20.
//

#include <vector>
#include "CommandsParamsFactory.h"
#include "../../CommandsParams/creation/new/NewCommandParams.h"
#include "../commandsName/CommandName.h"
#include "../../CommandsParams/creation/load/LoadCommandParams.h"
#include "../../CommandsParams/creation/dup/DupCommandParams.h"
#include "../../CommandsParams/management/save/SaveCommandParams.h"
#include "../../CommandsParams/noParams/NoParams.h"

namespace CLI{

    Params *CommandsParamsFactory::getParams(const std::string &commandName, const std::vector<std::string> &params)
    {
        switch (CommandName::getECommand(commandName))
        {
            case CommandName::E_DO_NOTHING: {
                return (Params *)(new NoParams());
            }
            case CommandName::E_NEW: {
                return (Params *)(new NewCommandParams(params));
            }
            case CommandName::E_LOAD:
                return (Params *)(new LoadCommandParams(params));
            case CommandName::E_DUP:
                return (Params *)(new DupCommandParams(params));
            case CommandName::E_SAVE:
                return (Params *)(new SaveCommandParams(params));
            case CommandName::E_SLICE:
                return NULL;
            case CommandName::E_REPLACE:
                return NULL;
            case CommandName::E_CONCAT:
                return NULL;
            case CommandName::E_PAIR:
                return NULL;
                /*....*/
            case CommandName::E_Last:
                break;
            default:
                return (Params *)(new NoParams());
        }
        return NULL;
    }

}