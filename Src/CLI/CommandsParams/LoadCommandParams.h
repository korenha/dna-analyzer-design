#ifndef DNAANALYZERPROJECT_LOADCOMMANDPARAMS_H
#define DNAANALYZERPROJECT_LOADCOMMANDPARAMS_H

#include <string>
#include <vector>
#include "../Params.h"

namespace CLI {

//#include "../DNA/DNAMetaData.h"
    struct LoadCommandParams: public Params
    {
        void set(const std::vector<std::string>& newParams);
        LoadCommandParams(const std::vector<std::string>& parmas);

    private:
        static size_t numDefault;

    };
}

#endif //DNAANALYZERPROJECT_LOADCOMMANDPARAMS_H
