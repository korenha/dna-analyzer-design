//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_COMMANDFACTORY_H
#define DNAANALYZERPROJECT_COMMANDFACTORY_H

#include "ICommand.h"
namespace CML{

class CommandFactory
{
public:
    enum ECommand{
        E_NEW,
        E_LOAD,
        //....
        E_Last
    };
public:
    static ICommand* getCommand(const std::string &command);

private:
    CommandFactory();
    CommandFactory(const CommandFactory&);

};

}
#endif //DNAANALYZERPROJECT_COMMANDFACTORY_H
