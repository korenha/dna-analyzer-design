#include <iostream>
#include <sstream>
#include "LoadCommandParams.h"
#include "../../Exception/MyException.h"

namespace CLI{
    size_t LoadCommandParams::numDefault = 1;
    LoadCommandParams::LoadCommandParams(const std::vector<std::string> &params)
    {
        m_params.resize(2);
        set(params);
    }

    void LoadCommandParams::set(const std::vector<std::string> &newParams)
    {
        if(newParams.size() > 2)
        {
            throw std::invalid_argument("too much arguments");
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
            std::stringstream name;
            name<<m_params[1]<<numDefault;
            m_params[1] = name.str();
            ++numDefault;
        }
    //support path
    }
}