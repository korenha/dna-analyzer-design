#ifndef DNAANALYZERPROJECT_NEWCOMMANDPARAMS_H
#define DNAANALYZERPROJECT_NEWCOMMANDPARAMS_H


namespace CML {

#include <string>
#include "IParams.h"
#include "../DNA/DNAMetaData.h"
    struct NewCommandParams: public CML::IParams
    {
        explicit NewCommandParams(const char* dna,const std::string& name="");
        const char* m_dna;
        std::string m_name;

    };
}

#endif //DNAANALYZERPROJECT_NEWCOMMANDPARAMS_H
