#ifndef DNAANALYZERPROJECT_NEWCOMMANDPARSING_H
#define DNAANALYZERPROJECT_NEWCOMMANDPARSING_H

#include <string>
#include "IParams.h"
#include "../Reader/StringReader.h"

namespace CLI {

//#include "../DNA/DNAMetaData.h"
    struct NewCommandParsing: public CLI::IParams
    {
        void set(const std::vector<std::string>& newParams);
        NewCommandParsing(const std::vector<std::string>& parmas);

    };
}

#endif //DNAANALYZERPROJECT_NEWCOMMANDPARSING_H
