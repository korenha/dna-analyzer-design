//
// Created by a on 7/7/20.
//

#include <sstream>
#include "LoadCommand.h"
#include "../../Reader/FileReader.h"
#include "../../DNA/IDNAData.h"

namespace CLI
{

    std::string LoadCommand::run(Params *params)
    {
        IDNAData::getDNAData().insert(DNAMetaData(FileReader(params->get()[0].c_str()),params->get()[1]));
        std::stringstream out;
        out << '['<<(IDNAData::getDNAData()).getId(params->get()[1])<<"] ";
        out << (IDNAData::getDNAData()).find(params->get()[1]).getName()<<": ";
        out << (IDNAData::getDNAData()).find(params->get()[1])<< std::endl;
        return out.str();

    }
}

