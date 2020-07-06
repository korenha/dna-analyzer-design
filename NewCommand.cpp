

//
// Created by a on 7/5/20.
//
namespace CML {

#include "NewCommand.h"
#include "Src/DNA/DNAData.h"
#include "Src/CML/NewCommandParsing.h"
#include "Src/Reader/ReaderConstChar.h"
    void CML::NewCommand::run()
    {
        NewCommandParsing* pareters=params;
        (DNAData::getDNAData()).insert(ReaderConstChar(pareters->m_dna),pareters->m_name)
    }

}