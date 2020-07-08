#ifndef DNAANALYZERPROJECT_DUPCOMMANDPARAMS_H
#define DNAANALYZERPROJECT_DUPCOMMANDPARAMS_H

#include "../Params.h"
#include <string>
#include <hash_map>

namespace CLI{
    struct DupCommandParams :public Params
    {
        void set(const std::vector<std::string>& newParams);
        DupCommandParams(const std::vector<std::string>& params);

    private:
        static __gnu_cxx::hash_map<size_t ,size_t > m_counterMap;

    };
}

#endif //DNAANALYZERPROJECT_DUPCOMMANDPARAMS_H
