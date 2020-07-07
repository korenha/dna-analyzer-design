#ifndef DNAANALYZERPROJECT_IPARAMS_H
#define DNAANALYZERPROJECT_IPARAMS_H

#include <vector>

namespace CLI
{
    struct IParams {
    public:
        virtual void set(const std::vector<std::string>& params)=0;
        const std::vector<std::string>& get(){ return m_params;}
        virtual ~IParams(){}

    protected:
        std::vector<std::string> m_params;
    };
}
#endif //DNAANALYZERPROJECT_IPARAMS_H
