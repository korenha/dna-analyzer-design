//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_ICREATIONCOMMAND_H
#define DNAANALYZERPROJECT_ICREATIONCOMMAND_H

#include "ICommand.h"

namespace CML{
    class ICreationCommand:public ICommand
    {
        std::string run(IParams* params)=0;
    };
}
#endif //DNAANALYZERPROJECT_ICREATIONCOMMAND_H
