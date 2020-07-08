#include <iostream>
#include <sstream>
#include "SaveCommandParams.h"
#include "../../../../Exception/MyException.h"
#include "../../../../DNA/colection/IDNAData.h"

namespace CLI
{

    SaveCommandParams::SaveCommandParams(const std::vector<std::string> &params)
    {
        m_params.resize(2);
        set(params);
    }

    void SaveCommandParams::set(const std::vector<std::string> &newParams)
    {
        if(newParams.size() > 3)
        {
            throw std::invalid_argument("Error: too much arguments");
        }

        if(newParams.empty())
        {
            throw std::invalid_argument("Error: missing argument");
        }

        m_params[0] = newParams[1];
        setTheFirstArgumentToBeId();

        if(newParams.size() == 2)
        {
            std::stringstream idAsString(m_params[0]);
            size_t id;
            idAsString>>id;
            m_params[1] = IDNAData::getDNAData().find(id).getName() + ".rawdna";
            return;
        }
        m_params[1] = newParams[2];
        if(newParams[2].find_last_of('.') == std::string::npos)
        {
            m_params[1]  += ".rawdna";
        }
    }

    void SaveCommandParams::setTheFirstArgumentToBeId()
    {

        if(m_params[0][0] == '@')
        {
            std::stringstream ss;
            ss << (IDNAData::getDNAData()).getId(m_params[0]);
            m_params[0].erase(0,1);
            ss >> m_params[0];
        } else
        if(m_params[0][0]=='#')
        {
            m_params[0].erase(0,1);
        } else
        {
            throw MyException("SyntaxError: Expected strt with @ in the second parameter");
        }
    }

}
