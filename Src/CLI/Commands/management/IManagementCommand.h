#ifndef DNAANALYZERPROJECT_IMANAGEMENTCOMMAND_H
#define DNAANALYZERPROJECT_IMANAGEMENTCOMMAND_H

#include <string>
#include "../../Params.h"
#include "../../ICommand.h"

namespace CLI{
    class IManagementCommand :public ICommand
    {
    public:
        std::string run(Params *params) =0;
    };
}

#endif //DNAANALYZERPROJECT_IMANAGEMENTCOMMAND_H
