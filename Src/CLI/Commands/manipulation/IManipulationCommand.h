#ifndef DNAANALYZERPROJECT_IMANIPULATIONCOMMAND_H
#define DNAANALYZERPROJECT_IMANIPULATIONCOMMAND_H

#include <string>
#include "../../CommandsParams/Params.h"
#include "../ICommand.h"

namespace CLI
{
    class IManipulationCommand: public ICommand
    {
    public:
        std::string run(Params *params) =0;
    };

}
#endif //DNAANALYZERPROJECT_IMANIPULATIONCOMMAND_H
