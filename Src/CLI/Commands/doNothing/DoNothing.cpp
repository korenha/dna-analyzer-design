//
// Created by a on 7/8/20.
//

#include <sstream>
#include "DoNothing.h"
namespace CLI{
    std::string CLI::DoNothing::run(CLI::Params *params)
    {
        std::stringstream ss("");
        return ss.str();
    }
}