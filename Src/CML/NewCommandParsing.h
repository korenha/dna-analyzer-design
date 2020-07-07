#ifndef DNAANALYZERPROJECT_NEWCOMMANDPARSING_H
#define DNAANALYZERPROJECT_NEWCOMMANDPARSING_H

#include <string>
#include "IParams.h"
#include "../Reader/StringReader.h"

namespace CML {

//#include "../DNA/DNAMetaData.h"
    struct NewCommandParsing: public CML::IParams
    {
        void set(const std::vector<std::string>& newParams);
        NewCommandParsing(const std::vector<std::string>& parmas);

    };
}

#endif //DNAANALYZERPROJECT_NEWCOMMANDPARSING_H
