#ifndef DNAANALYZERPROJECT_DUPCOMMANDPARAMS_H
#define DNAANALYZERPROJECT_DUPCOMMANDPARAMS_H

#include "../Params.h"
#include <string>
namespace CLI{
    struct DupCommandParams :public Params
    {
        void set(const std::vector<std::string>& newParams);
        DupCommandParams(const std::vector<std::string>& params);

    private:
        static size_t numDefault;
    };
}

#endif //DNAANALYZERPROJECT_DUPCOMMANDPARAMS_H
