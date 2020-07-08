#ifndef DNAANALYZERPROJECT_LOADCOMMAND_H
#define DNAANALYZERPROJECT_LOADCOMMAND_H


#include <string>
#include "../../../CommandsParams/Params.h"
#include "../ICreationCommand.h"

namespace CLI{
class LoadCommand:public ICreationCommand
{
public:
    std::string run(Params* params);

};
}

#endif //DNAANALYZERPROJECT_LOADCOMMAND_H
