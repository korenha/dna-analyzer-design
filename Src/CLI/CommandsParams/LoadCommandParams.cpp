#include <iostream>
#include <sstream>
#include "LoadCommandParams.h"
#include "../../Exception/MyException.h"

namespace CLI{
    LoadCommandParams::LoadCommandParams(const std::vector<std::string> &parmas)
    {
        m_params.resize(3);
        set(parmas);
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
        m_params[0] = std::string(newParams[0].begin(),newParams[0].begin() + positionIndex);
        m_params[1] = std::string(newParams[0].begin() ,newParams[0].begin() + 32);
        if(newParams.size() == 2)
        {
            if(newParams[1][0] != '@')
            {
                throw MyException("SyntaxError: Expected strt with @ in the second parameter");
            }
            m_params[2] = newParams[1];
            m_params[2].erase(m_params[1].begin());
        }
        else
        {
            m_params[2] = m_params[0];
            if(positionIndex > 40)
            {
                m_params[2].erase(32,m_params[1].size() - 35);
            }

            std::stringstream name;
            name<<m_params[2]<<numDefault;
            m_params[2] = name.str();
            ++numDefault;
        }
        m_params.push_back(std::string(newParams[0].begin() + positionIndex,newParams[0].end()));
    //add path
    }
}