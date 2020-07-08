#include <iostream>
#include <sstream>
#include <backward/hash_map>
#include "LoadCommandParams.h"
#include "../../Exception/MyException.h"
#include "../../Utils/HashForString.h"

namespace CLI{
    __gnu_cxx::hash_map<std::string ,size_t > LoadCommandParams::m_counterMap;
    LoadCommandParams::LoadCommandParams(const std::vector<std::string> &params)
    {
        m_params.resize(2);
        set(params);
    }

    void LoadCommandParams::set(const std::vector<std::string> &newParams)
    {
        if(newParams.size() > 2)
        {
            throw std::invalid_argument("Error: too much arguments");
        }
        if(newParams.size() == 0)
        {
            throw std::invalid_argument("missing argument");
        }
        size_t positionIndex = newParams[0].find_last_of('.');
        m_params[0] = newParams[0];
        if(newParams.size() == 2)
        {
            if(newParams[1][0] != '@')
            {
                throw MyException("SyntaxError: Expected strt with @ in the second parameter");
            }
            m_params[1] = newParams[1];
            m_params[1].erase(m_params[1].begin());
        }
        else
        {
            m_params[1] = std::string(newParams[0].begin() ,newParams[0].begin() + positionIndex);
            ++m_counterMap[m_params[1]];
            std::stringstream name;
            name<<m_params[1]<<m_counterMap[m_params[1]];
            m_params[1] = name.str();
        }
    //support path
    }
}