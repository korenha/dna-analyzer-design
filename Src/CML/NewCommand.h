#ifndef DNAANALYZERPROJECT_NEWCOMMAND_H
#define DNAANALYZERPROJECT_NEWCOMMAND_H
#include "ICreationCommand.h"
#include "NewCommandParsing.h"
namespace CML {

    class NewCommand :public ICreationCommand
    {
        void run(struct NewCommandParsing* params);
    };

}
#endif //DNAANALYZERPROJECT_NEWCOMMAND_H
