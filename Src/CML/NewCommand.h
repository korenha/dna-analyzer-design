//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_NEWCOMMAND_H
#define DNAANALYZERPROJECT_NEWCOMMAND_H

#include "ICreationCommand.h"

namespace CML{

class NewCommand:public ICreationCommand
{
    std::string run(IParams* params);

};

}
#endif //DNAANALYZERPROJECT_NEWCOMMAND_H
