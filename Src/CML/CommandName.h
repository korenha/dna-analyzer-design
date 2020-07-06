//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_COMMANDNAME_H
#define DNAANALYZERPROJECT_COMMANDNAME_H

#include <string>
namespace CML{
class CommandName
{
public:
    enum ECommand{
        E_NEW,
        E_LOAD,
        //....
                E_Last
    };
    static ECommand getECommand(const std::string& commandName);
};
}

#endif //DNAANALYZERPROJECT_COMMANDNAME_H
