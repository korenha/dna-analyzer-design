#ifndef DNAANALYZERPROJECT_NEWCOMMANDPARSING_H
#define DNAANALYZERPROJECT_NEWCOMMANDPARSING_H

#include <string>
#include "IParams.h"
namespace CML {

//#include "../DNA/DNAMetaData.h"
    struct NewCommandParsing: public CML::IParams
    {
        NewCommandParsing(const std::string &params);
        std::string m_dna;
        std::string m_name;

    };
}

#endif //DNAANALYZERPROJECT_NEWCOMMANDPARSING_H
