#include <stdexcept>
#include <sstream>
#include "NewCommandParsing.h"
#include "../Exception/MyException.h"

namespace CML{

    NewCommandParsing::NewCommandParsing(const std::vector<std::string>& parmas)
    {
        m_params.resize(2);
        set(parmas);
    }

    void NewCommandParsing::set(const std::vector<std::string> &newParams)
    {
        static size_t numDefault = 1;
        if(newParams.size() > 2)
        {
            throw std::invalid_argument("too much arguments");
        }
        if(newParams.size() == 0)
        {
            throw std::invalid_argument("missing argument");
        }
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
            std::stringstream name;
            name<<"seq"<<numDefault;
            m_params[1] = name.str();
            ++numDefault;

        }


    }

}

