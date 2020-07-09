//
// Created by a on 7/7/20.
//

#include <sstream>
#include "LoadCommand.h"
#include "../../../../Reader/fileReader/FileReader.h"
#include "../../../../DNA/colection/IDNAData.h"
#include "../../../../Writer/file/FileWriter.h"

namespace CLI
{

    std::string LoadCommand::run(Params *params)
    {
        FileReader file(params->get()[0].c_str());
        std::string seq = file.read();
        DNAMetaData newDna(DnaSequence(seq),params->get()[1]);
        IDNAData::getDNAData().insert(newDna);
        std::stringstream out;
        DNAMetaData temp  = (IDNAData::getDNAData()).find(params->get()[1]);
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
    //Add for every obj counter

}

