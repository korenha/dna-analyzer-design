#include <stdexcept>
#include <sstream>
#include "DupCommandParams.h"
#include "../../Exception/MyException.h"

namespace CLI
{

    size_t DupCommandParams::numDefault = 1;
    DupCommandParams::DupCommandParams(const std::vector<std::string> &params)
    {
        m_params.resize(1);
        set(params);
    }

    void DupCommandParams::set(const std::vector<std::string> &newParams)
    {
        if(newParams.size() > 2)
        {
            throw std::invalid_argument("Error: invalid_argument:: too much arguments");
        }
        if(newParams.size() == 0)
        {
            throw std::invalid_argument("Error: invalid_argument:: missing argument");
        }
        m_params[0] = newParams[0];

        if(newParams[0][0] != '#')
        {
            throw MyException("Error: SyntaxError: Expected start id with # in the second parameter");
        }

        if(newParams.size() == 2)
        {
            if(newParams[1][0] != '@')
            {
                throw MyException("Error: SyntaxError: Expected start with @ in the second parameter");
            }
            m_params.push_back(newParams[1]);
            m_params[1].erase(m_params[1].begin());
        }

    }
}
