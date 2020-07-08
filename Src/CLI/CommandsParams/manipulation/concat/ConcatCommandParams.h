#ifndef DNAANALYZERPROJECT_CONCATCOMMANDPARAMS_H
#define DNAANALYZERPROJECT_CONCATCOMMANDPARAMS_H

#include "../../Params.h"

namespace CLI
{
    struct ConcatCommandParams: public Params
    {
    public:
        void set(const std::vector<std::string>& newParams);
        ConcatCommandParams(const std::vector<std::string>& params);
    };
}

#endif //DNAANALYZERPROJECT_CONCATCOMMANDPARAMS_H
