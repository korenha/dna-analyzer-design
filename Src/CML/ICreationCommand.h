#ifndef DNAANALYZERPROJECT_ICREATIONCOMMAND_H
#define DNAANALYZERPROJECT_ICREATIONCOMMAND_H
#include "ICommand.h"

namespace CML
{


    class ICreationCommand : public CML::ICommand
    {
        virtual void run(IParams *params) = 0;

    };
}
#endif //DNAANALYZERPROJECT_ICREATIONCOMMAND_H
