

//
// Created by a on 7/5/20.
//
namespace CML {

#include "NewCommand.h"
#include "../DNA/DNAData.h"
#include "NewCommandParams.h"
#include "../Reader/ReaderConstChar.h"
    void CML::NewCommand::run(NewCommandParams *params)
    {
        NewCommandParams* pareters=params;
        (DNAData::getDNAData()).insert(ReaderConstChar(pareters->m_dna),pareters->m_name)
    }

}