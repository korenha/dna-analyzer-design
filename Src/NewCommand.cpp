#include <iostream>
#include "NewCommand.h"
#include "../DNA/IDNAData.h"
#include "../CML/NewCommandParsing.h"
#include "../Reader/StringReader.h"

namespace CML {
    void NewCommand::run(IParams* params)const
    {
        std::cout<<"i In NEW command\n";
        (IDNAData::getDNAData()).insert(DNAMetaData(StringReader(((NewCommandParsing*)params)->m_dna),((NewCommandParsing*)params)->m_name));
    }

}