#include <stdexcept>
#include <sstream>
#include "NewCommandParams.h"
#include "../../../../Exception/MyException.h"

namespace CLI{

    size_t NewCommandParams::numDefault = 1;
    NewCommandParams::NewCommandParams(const std::vector<std::string>& parmas)
    {
        m_params.resize(2);
        set(parmas);
    }

    void NewCommandParams::set(const std::vector<std::string> &newParams)
    {
        if(newParams.size() > 3)
        {
            throw std::invalid_argument("too much arguments");
        }
        if(newParams.size() == 1)
        {
            throw std::invalid_argument("missing argument");
        }
        m_params[0] = newParams[1];
        if(newParams.size() == 1)
        {
            if(newParams[2][0] != '@')
            {
                throw MyException("SyntaxError: Expected strt with @ in the second parameter");
            }
            m_params[1] = newParams[2];
            m_params[1].erase(0,1);
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

