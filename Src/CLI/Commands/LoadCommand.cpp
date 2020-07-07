//
// Created by a on 7/7/20.
//

#include <sstream>
#include "LoadCommand.h"
#include "../../Reader/FileReader.h"
#include "../../DNA/IDNAData.h"
#include "../../Writer/FileWriter.h"

namespace CLI
{

    std::string LoadCommand::run(Params *params)
    {
        IDNAData::getDNAData().insert(DNAMetaData(FileReader(params->get()[0].c_str()),params->get()[1]));
        std::stringstream out;
        DNAMetaData temp = (IDNAData::getDNAData()).find(params->get()[1]);
        out << '['<<IDNAData::getDNAData().getId(params->get()[1])<<"] ";
        out << temp.getName()<<": ";
        if(temp.getLength() > 40)
        {
            out << temp.slice(0,32)<<"..."<<temp.slice(temp.getLength() - 3,temp.getLength())<< std::endl;
        }
        else
        {
            out<<temp<<std::endl;
        }
        return out.str();

    }
}

