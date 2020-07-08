#ifndef DNAANALYZERPROJECT_REPLACECOMMANDPARAMS_H
#define DNAANALYZERPROJECT_REPLACECOMMANDPARAMS_H
#include "../../Params.h"

namespace CLI{
    struct ReplaceCommandParams :public Params
    {
    public:
        void set(const std::vector<std::string>& newParams);
        ReplaceCommandParams(const std::vector<std::string>& params);

    };
}

#endif //DNAANALYZERPROJECT_REPLACECOMMANDPARAMS_H
