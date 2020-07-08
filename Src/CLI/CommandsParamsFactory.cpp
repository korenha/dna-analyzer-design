//
// Created by a on 7/6/20.
//

#include <vector>
#include "CommandsParamsFactory.h"
#include "CommandsParams/NewCommandParams.h"
#include "CommandName.h"
#include "CommandsParams/LoadCommandParams.h"
#include "CommandsParams/DupCommandParams.h"
#include "CommandsParams/management/SaveCommandParams.h"

namespace CLI{

    Params *CommandsParamsFactory::getParams(const std::string &commandName, const std::vector<std::string> &params)
    {
        switch (CommandName::getECommand(commandName))
        {
            case CommandName::E_NEW: {
                return (Params *)(new NewCommandParams(params));
            }
            case CommandName::E_LOAD:
                return (Params *)(new LoadCommandParams(params));
            case CommandName::E_DUP:
                return (Params *)(new DupCommandParams(params));
            case CommandName::E_SAVE:
                return (Params *)(new SaveCommandParams(params));

                /*....*/
            case CommandName::E_Last:
                break;
            default:
                return NULL;
        }
        return NULL;
    }

}