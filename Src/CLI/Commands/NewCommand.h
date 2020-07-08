//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_NEWCOMMAND_H
#define DNAANALYZERPROJECT_NEWCOMMAND_H

#include "../ICreationCommand.h"

namespace CLI{

    class NewCommand:public ICreationCommand
    {
    public:
        std::string run(Params* params);

    };

}
#endif //DNAANALYZERPROJECT_NEWCOMMAND_H
