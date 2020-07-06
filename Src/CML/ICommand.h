#ifndef DNAANALYZERPROJECT_ICOMMAND_H
#define DNAANALYZERPROJECT_ICOMMAND_H
struct IParams;
#include "../DNA/IDNAData.h"
namespace CML {


    class ICommand
    {
    public:
        virtual void run(IParams *params) = 0;
        virtual ~ICommand(){}
    };
}

#endif //DNAANALYZERPROJECT_ICOMMAND_H
