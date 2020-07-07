#ifndef DNAANALYZERPROJECT_NEWCOMMAND_H
#define DNAANALYZERPROJECT_NEWCOMMAND_H
#include "ICreationCommand.h"
#include "NewCommandParsing.h"
namespace CML {

    class NewCommand :public ICommand
    {
    public:
        void run(IParams *params)const;
    };

}
#endif //DNAANALYZERPROJECT_NEWCOMMAND_H
