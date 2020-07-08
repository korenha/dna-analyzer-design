//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_COMMANDNAME_H
#define DNAANALYZERPROJECT_COMMANDNAME_H

#include <string>
namespace CLI{
class CommandName
{
public:
    enum ECommand{
        E_DO_NOTHING,
        E_NEW,
        E_LOAD,
        E_DUP,
        E_SLICE,
        E_REPLACE,
        E_CONCAT,
        E_PAIR,
        E_SAVE,
        //....
        E_QUIT,
        E_Last
    };
    static ECommand getECommand(const std::string& commandName);
};
}

#endif //DNAANALYZERPROJECT_COMMANDNAME_H
