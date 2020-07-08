#ifndef DNAANALYZERPROJECT_SAVECOMMANDPARAMS_H
#define DNAANALYZERPROJECT_SAVECOMMANDPARAMS_H

#include "../../Params.h"
#include <string>
namespace CLI{
    struct SaveCommandParams : public Params
    {
        void set(const std::vector<std::string>& newParams);
        SaveCommandParams(const std::vector<std::string>& params);

    private:
        void setTheFirstArgumentToBeId();

    };
}

#endif //DNAANALYZERPROJECT_SAVECOMMANDPARAMS_H
