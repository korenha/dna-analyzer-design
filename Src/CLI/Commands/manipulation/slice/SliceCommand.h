#ifndef DNAANALYZERPROJECT_SLICECOMMAND_H
#define DNAANALYZERPROJECT_SLICECOMMAND_H
#include "../IManipulationCommand.h"

namespace CLI
{
    class SliceCommand:public IManipulationCommand
    {
    public:
        std::string run(Params *params);
    };

}
#endif //DNAANALYZERPROJECT_SLICECOMMAND_H
