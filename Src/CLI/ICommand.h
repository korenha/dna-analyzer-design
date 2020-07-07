//
// Created by a on 7/6/20.
//

#ifndef DNAANALYZERPROJECT_ICOMMAND_H
#define DNAANALYZERPROJECT_ICOMMAND_H

#include "IParams.h"

namespace CLI{
    class ICommand{
    public:
        virtual std::string run(IParams* params)=0;
        virtual ~ICommand(){}
    };
}
#endif //DNAANALYZERPROJECT_ICOMMAND_H
