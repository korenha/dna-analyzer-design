#ifndef DNAANALYZERPROJECT_ICREATIONCOMMAND_H
#define DNAANALYZERPROJECT_ICREATIONCOMMAND_H
#include "ICommand.h"

namespace CML
{


    class ICreationCommand : public ICommand
    {
    public:
        void run(IParams *params)const{}
    };

}
#endif //DNAANALYZERPROJECT_ICREATIONCOMMAND_H
