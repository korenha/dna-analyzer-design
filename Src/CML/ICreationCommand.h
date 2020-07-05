#ifndef DNAANALYZERPROJECT_ICREATIONCOMMAND_H
#define DNAANALYZERPROJECT_ICREATIONCOMMAND_H

#include "../CML/ICommand.h"

class ICreationCommand: public ICommand
{
    virtual void run()=0;
};
#endif //DNAANALYZERPROJECT_ICREATIONCOMMAND_H
