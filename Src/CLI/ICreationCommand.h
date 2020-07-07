//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_ICREATIONCOMMAND_H
#define DNAANALYZERPROJECT_ICREATIONCOMMAND_H

#include "ICommand.h"

namespace CLI{
    class ICreationCommand:public ICommand
    {
    public:
        std::string run(Params* params)=0;
    };
}
#endif //DNAANALYZERPROJECT_ICREATIONCOMMAND_H
