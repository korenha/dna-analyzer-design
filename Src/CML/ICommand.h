#ifndef DNAANALYZERPROJECT_ICOMMAND_H
#define DNAANALYZERPROJECT_ICOMMAND_H
struct IParams;
#include "../DNA/DNAData.h"
namespace CML {


    class ICommand
    {
        virtual void run(IParams *params) = 0;
    };
}

#endif //DNAANALYZERPROJECT_ICOMMAND_H
