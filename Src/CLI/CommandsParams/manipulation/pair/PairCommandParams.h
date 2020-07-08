#ifndef DNAANALYZERPROJECT_PAIRCOMMANDPARAMS_H
#define DNAANALYZERPROJECT_PAIRCOMMANDPARAMS_H
#include "../../Params.h"

namespace CLI
{
    struct PairCommandParams :public Params
    {
        void set(const std::vector<std::string>& newParams);
        PairCommandParams(const std::vector<std::string>& params);
    };
}


#endif //DNAANALYZERPROJECT_PAIRCOMMANDPARAMS_H
