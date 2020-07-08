#include <sstream>
#include "SaveCommand.h"
#include "../../../Writer/FileWriter.h"
#include "../../../DNA/IDNAData.h"

namespace CLI
{

    std::string SaveCommand::run(Params *params)
    {
        std::stringstream ss,writen;
        ss<<params->get()[0];
        size_t id;
        ss>>id;
        writen<<IDNAData::getDNAData().find(id).getDNASeq();
        std::string writeToFile = (writen.str());
        FileWriter(params->get()[1]).write(writeToFile.c_str());
        return "";
    }
}