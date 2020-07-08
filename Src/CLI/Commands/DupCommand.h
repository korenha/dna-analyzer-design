#ifndef DNAANALYZERPROJECT_DUPCOMMAND_H
#define DNAANALYZERPROJECT_DUPCOMMAND_H

#include <string>
#include "../ICreationCommand.h"
#include <hash_map>
namespace CLI{
    struct DupCommand :public ICreationCommand
    {
    public:
        std::string run(Params* params);
    };
}

#endif //DNAANALYZERPROJECT_DUPCOMMAND_H
