#include <stdexcept>
#include <sstream>
#include "NewCommandParams.h"
#include "../../../../Exception/MyException.h"
#include "../../../../Utils/HashForString.h"
namespace CLI{

    __gnu_cxx::hash_map<std::string ,size_t > NewCommandParams::m_counterMap;
    NewCommandParams::NewCommandParams(const std::vector<std::string>& parmas)
    {
        m_params.resize(2);
        if(m_counterMap.empty())
        {
            ++m_counterMap["seq"];
        }
        set(parmas);
    }

    void NewCommandParams::set(const std::vector<std::string> &newParams)
    {
        if(newParams.size() > 3)
        {
            throw std::invalid_argument("too much arguments");
        }
        if(newParams.size() == 1 || newParams[1].empty())
        {
            throw std::invalid_argument("missing argument");
        }
        m_params[0] = newParams[1];
        m_params[1] = "seq";
        std::string name = "seq";
        if(newParams.size() == 3)
        {
            if (newParams[2][0] != '@')
            {
                throw MyException("SyntaxError: Expected strt with @ in the second parameter");
            }
            name = newParams[2];
            name.erase(0,1);
            m_params[1] = name;
        }

        if(m_counterMap[name] != 0)
        {
            std::stringstream ss;
            ss << name<<m_counterMap[name];
            m_params[1] = ss.str();
            ++m_counterMap[name];
        }
        ++m_counterMap[m_params[1]];

    }

}

