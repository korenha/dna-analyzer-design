//
// Created by a on 7/8/20.
//

#ifndef DNAANALYZERPROJECT_ICONTROLCOMMAND_H
#define DNAANALYZERPROJECT_ICONTROLCOMMAND_H

#include "../ICommand.h"

namespace CLI{
    class IControlCommand:public ICommand
    {
        std::string run(Params* params)=0;
    };
}

#endif //DNAANALYZERPROJECT_ICONTROLCOMMAND_H
