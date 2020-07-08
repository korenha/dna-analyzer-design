#ifndef DNAANALYZERPROJECT_LOADCOMMANDPARAMS_H
#define DNAANALYZERPROJECT_LOADCOMMANDPARAMS_H

#include <string>
#include <vector>
#include <hash_map>
#include "../Params.h"

namespace CLI {

//#include "../DNA/DNAMetaData.h"
    struct LoadCommandParams: public Params
    {
        void set(const std::vector<std::string>& newParams);
        LoadCommandParams(const std::vector<std::string>& params);

    private:
        static __gnu_cxx::hash_map<std::string ,size_t > m_counterMap;

    };
}

#endif //DNAANALYZERPROJECT_LOADCOMMANDPARAMS_H
