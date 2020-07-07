//
// Created by a on 7/6/20.
//

#include <vector>
#include "CommandsParsingFactory.h"
#include "NewCommandParsing.h"
#include "CommandName.h"
namespace CML{

    IParams *CommandsParsingFactory::getParams(const std::string &commandName, const std::vector<std::string> &params)
    {
        switch (CommandName::getECommand(commandName))
        {
            case CommandName::E_NEW:
                return (IParams*)(new NewCommandParsing(params));
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