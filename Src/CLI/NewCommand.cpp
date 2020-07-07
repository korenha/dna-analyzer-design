//
// Created by a on 7/6/20.
//

#include <iostream>
#include "NewCommand.h"
#include "../DNA/IDNAData.h"
#include "NewCommandParsing.h"
#include "../Reader/StringReader.h"
#include "sstream"
namespace CLI{
    std::string NewCommand::run(IParams *params) {
        std::vector<std::string> parameters = params->get();
        DNAMetaData newDna(StringReader(parameters.front()),parameters[1]);
        (IDNAData::getDNAData()).insert(newDna);
        std::stringstream out;
        out << '['<<(IDNAData::getDNAData()).getId(parameters[1])<<"] ";
        out << (IDNAData::getDNAData()).find(parameters[1]).getName()<<": ";
        out << (IDNAData::getDNAData()).find(parameters[1])<< std::endl;
        return out.str();
    }
}