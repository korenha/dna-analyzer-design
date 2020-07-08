//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_ICOMMAND_H
#define DNAANALYZERPROJECT_ICOMMAND_H

#include "../CommandsParams/Params.h"
#include "../../DNA/colection/IDNAData.h"

namespace CLI{
    class ICommand{
    public:
        virtual std::string run(Params* params)=0;
        virtual ~ICommand(){}
    };
}
#endif //DNAANALYZERPROJECT_ICOMMAND_H
