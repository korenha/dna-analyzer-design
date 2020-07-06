#include "NewCommand.h"
#include "../DNA/IDNAData.h"
#include "../CML/NewCommandParsing.h"
#include "../Reader/StringReader.h"

namespace CML {
    void NewCommand::run(NewCommandParsing* params)
    {
        (IDNAData::getDNAData()).insert(DNAMetaData(StringReader(params->m_dna),params->m_name));
    }

}