#include <iostream>
#include <sstream>
#include <backward/hash_map>
#include "LoadCommandParams.h"
#include "../../../../Exception/MyException.h"
#include "../../../../Utils/HashForString.h"

namespace CLI{
    __gnu_cxx::hash_map<std::string ,size_t > LoadCommandParams::m_counterMap;
    LoadCommandParams::LoadCommandParams(const std::vector<std::string> &params)
    {
        m_params.resize(2);
        set(params);
    }

    void LoadCommandParams::set(const std::vector<std::string> &newParams)
    {
        if(newParams.size() > 3)
        {
            throw std::invalid_argument("Error: too much arguments");
        }
        if(newParams.size() == 1)
        {
            throw std::invalid_argument("missing argument");
        }
        size_t positionIndex = newParams[1].find_last_of('.');
        m_params[0] = newParams[1];
        if(newParams.size() == 3)
        {
            if(newParams[2][0] != '@')
            {
                throw MyException("SyntaxError: Expected strt with @ in the second parameter");
            }
            m_params[1] = newParams[2];
            m_params[1].erase(m_params[1].begin());
        }
        else
        {
            m_params[1] = std::string(newParams[1].begin() ,newParams[1].begin() + positionIndex);
            ++m_counterMap[m_params[1]];
            std::stringstream name;
            name<<m_params[1]<<m_counterMap[m_params[1]];
            m_params[1] = name.str();
        }
    //support path
    }
}