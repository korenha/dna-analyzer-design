#ifndef DNAANALYZERPROJECT_NEWCOMMAND_H
#define DNAANALYZERPROJECT_NEWCOMMAND_H
namespace CML {
#include "ICreationCommand.h"
    class NewCommand :public CML::ICreationCommand
    {
        void run(struct NewCommandParams *params);

    };

}
#endif //DNAANALYZERPROJECT_NEWCOMMAND_H
