#ifndef DNAANALYZERPROJECT_CONCATCOMMAND_H
#define DNAANALYZERPROJECT_CONCATCOMMAND_H

#include "../IManipulationCommand.h"

namespace CLI
{
    class ConcatCommand :public IManipulationCommand
    {
    public:
        std::string run(Params *params);
    };

}
#endif //DNAANALYZERPROJECT_CONCATCOMMAND_H
