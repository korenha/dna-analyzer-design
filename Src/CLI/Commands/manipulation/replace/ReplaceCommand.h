#ifndef DNAANALYZERPROJECT_REPLACECOMMAND_H
#define DNAANALYZERPROJECT_REPLACECOMMAND_H
#include "../IManipulationCommand.h"

namespace CLI
{
    class ReplaceCommand:public IManipulationCommand
    {
    public:
        std::string run(Params *params);
    };

}
#endif //DNAANALYZERPROJECT_REPLACECOMMAND_H
