//
// Created by a on 7/6/20.
//

#include <vector>
#include "CommandsParsingFactory.h"
#include "NewCommandParsing.h"
namespace CML{
    std::string commandsName[CommandsParsingFactory::E_Last] = {};

    IParams *CommandsParsingFactory::getParams(const std::string &params)
    {
        unsigned int indexCommand;
        for (indexCommand = 0; indexCommand < E_Last &&  params != commandsName[indexCommand]; ++indexCommand);
        EPCommand command = static_cast<EPCommand>(indexCommand);
        switch (command)
        {
            case E_NEW:
                return new NewCommandParsing(params);
            case E_LOAD:
                break;
                /*....*/
            case E_Last:
                break;
            default:
                return NULL;
        }
        return NULL;
    }

}