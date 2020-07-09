#ifndef DNAANALYZERPROJECT_NEWCOMMANDPARAMS_H
#define DNAANALYZERPROJECT_NEWCOMMANDPARAMS_H

#include <string>
#include <hash_map>
#include "../../Params.h"
#include "../../../../Reader/string/StringReader.h"

namespace CLI {

//#include "../DNA/DNAMetaData.h"
    struct NewCommandParams: public CLI::Params
    {
    public:
        void set(const std::vector<std::string>& newParams);
        NewCommandParams(const std::vector<std::string>& parmas);

    private:
        static __gnu_cxx::hash_map<std::string ,size_t > m_counterMap;


    };
}

#endif //DNAANALYZERPROJECT_NEWCOMMANDPARAMS_H
