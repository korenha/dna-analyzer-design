#include "NewCommand.h"
#include "../DNA/IDNAData.h"
#include "../CML/NewCommandParsing.h"
#include "../Reader/StringReader.h"

namespace CML {
    void NewCommand::run(IParams* params)
    {
        (IDNAData::getDNAData()).insert(DNAMetaData(StringReader(((NewCommandParsing*)params)->m_dna),((NewCommandParsing*)params)->m_name));
    }

}