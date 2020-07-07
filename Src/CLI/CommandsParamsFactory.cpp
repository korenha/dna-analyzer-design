//
// Created by a on 7/6/20.
//

#include <vector>
#include "CommandsParamsFactory.h"
#include "NewCommandParams.h"
#include "CommandName.h"
namespace CLI{

    Params *CommandsParamsFactory::getParams(const std::string &commandName, const std::vector<std::string> &params)
    {
        switch (CommandName::getECommand(commandName))
        {
            case CommandName::E_NEW: {
                return (Params *)(new NewCommandParams(params));
            }
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