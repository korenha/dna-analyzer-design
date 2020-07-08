#ifndef DNAANALYZERPROJECT_DONOTHING_H
#define DNAANALYZERPROJECT_DONOTHING_H

#include <string>
#include "../ICommand.h"

namespace CLI{

    class DoNothing:public ICommand
    {
    public:
        std::string run(Params* params);
    };

}
#endif //DNAANALYZERPROJECT_DONOTHING_H
