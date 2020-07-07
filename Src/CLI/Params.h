#ifndef DNAANALYZERPROJECT_PARAMS_H
#define DNAANALYZERPROJECT_PARAMS_H

#include <vector>

namespace CLI
{
    struct Params {
    public:
        virtual void set(const std::vector<std::string>& params)=0;
        const std::vector<std::string>& get(){ return m_params;}
        virtual ~Params(){}

    protected:
        std::vector<std::string> m_params;
    };
}
#endif //DNAANALYZERPROJECT_PARAMS_H
