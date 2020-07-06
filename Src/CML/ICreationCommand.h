#ifndef DNAANALYZERPROJECT_ICREATIONCOMMAND_H
#define DNAANALYZERPROJECT_ICREATIONCOMMAND_H
#include "ICommand.h"

namespace CML
{


    class ICreationCommand : public ICommand
    {
    public:
        virtual void run(IParams *params){}

    };

}
#endif //DNAANALYZERPROJECT_ICREATIONCOMMAND_H
