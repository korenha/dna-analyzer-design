#ifndef DNAANALYZERPROJECT_PAIRCOMMAND_H
#define DNAANALYZERPROJECT_PAIRCOMMAND_H
#include "../IManipulationCommand.h"

namespace CLI
{
    class PairCommand:public IManipulationCommand
    {
    public:
        std::string run(Params *params);
    };

}
#endif //DNAANALYZERPROJECT_PAIRCOMMAND_H
