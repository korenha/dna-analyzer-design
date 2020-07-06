#ifndef DNAANALYZERPROJECT_NEWCOMMAND_H
#define DNAANALYZERPROJECT_NEWCOMMAND_H
#include "ICreationCommand.h"
#include "NewCommandParsing.h"
namespace CML {

    class NewCommand :public ICreationCommand
    {
    public:
        virtual void run(struct IParams* params);
    };

}
#endif //DNAANALYZERPROJECT_NEWCOMMAND_H
