#ifndef DNAANALYZERPROJECT_SLICECOMMANDPARAMS_H
#define DNAANALYZERPROJECT_SLICECOMMANDPARAMS_H
#include "../../Params.h"

namespace CLI{
    struct SliceCommandParams:public Params
    {
    public:
        void set(const std::vector<std::string>& newParams);
        SliceCommandParams(const std::vector<std::string>& params);
    };
}

#endif //DNAANALYZERPROJECT_SLICECOMMANDPARAMS_H
