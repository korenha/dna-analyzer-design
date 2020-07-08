#ifndef DNAANALYZERPROJECT_NOPARAMS_H
#define DNAANALYZERPROJECT_NOPARAMS_H

#include "../Params.h"
#include <string>
namespace CLI{
    struct NoParams:Params
    {
        void set(const std::vector<std::string>& newParams){}
    };
}

#endif //DNAANALYZERPROJECT_NOPARAMS_H
