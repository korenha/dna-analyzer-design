#ifndef DNAANALYZERPROJECT_SAVECOMMAND_H
#define DNAANALYZERPROJECT_SAVECOMMAND_H

#include "IManagementCommand.h"

namespace CLI{
    class SaveCommand:public IManagementCommand
    {
    public:
        std::string run(Params *params);
    };

}
#endif //DNAANALYZERPROJECT_SAVECOMMAND_H
