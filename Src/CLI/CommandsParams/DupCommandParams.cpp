#include <stdexcept>
#include <sstream>
#include "DupCommandParams.h"
#include "../../Exception/MyException.h"
#include "../../DNA/IDNAData.h"

namespace CLI
{
    __gnu_cxx::hash_map<size_t ,size_t > DupCommandParams::m_counterMap;
    DupCommandParams::DupCommandParams(const std::vector<std::string> &params)
    {
        m_params.resize(2);
        set(params);
    }

    void DupCommandParams::set(const std::vector<std::string> &newParams)
    {
        if(newParams.size() > 2)
        {
            throw std::invalid_argument("Error: invalid_argument:: too much arguments");
        }
        if(newParams.empty())
        {
            throw std::invalid_argument("Error: invalid_argument:: missing argument");
        }
        m_params[0] = newParams[0];

        if(newParams[0][0] != '#')
        {
            throw MyException("Error: SyntaxError: Expected start id with # in the second parameter");
        }
        m_params[0].erase(0,1);
        if(newParams.size() == 2)
        {
            if(newParams[1][0] != '@')
            {
                throw MyException("Error: SyntaxError: Expected start with @ in the second parameter");
            }
            m_params.push_back(newParams[1]);
            m_params[1].erase(m_params[1].begin());
        }
        else
        {
            size_t id;
            std::stringstream name;
            std::istringstream(m_params[0]) >> id;
            ++m_counterMap[id];
            name<<IDNAData::getDNAData().find(id).getName()<<"_"<<m_counterMap[id];
            m_params[1]  = name.str();
        }

    }
}
