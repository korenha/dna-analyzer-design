#include <sstream>
#include "DupCommand.h"
#include "../../DNA/DNAMetaData.h"
#include "../../DNA/IDNAData.h"
#include <string>

namespace CLI
{
    std::string DupCommand::run(Params *params)
    {
        size_t id;
        std::vector<std::string> parameters(params->get());
        std::stringstream string1,out;
        string1 << parameters[0];
        string1 >> id;

        DNAMetaData other = IDNAData::getDNAData().find(id);
        IDNAData::getDNAData().insert(DNAMetaData(other, parameters[1]));
        out << '['<<IDNAData::getDNAData().getId(parameters[1])<<"] ";
        out << parameters[1]<<": ";
        out << IDNAData::getDNAData().find(parameters[1])<<std::endl;
        return out.str();
    }
}