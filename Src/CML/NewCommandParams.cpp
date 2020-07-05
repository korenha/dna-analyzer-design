//
// Created by a on 7/5/20.
//

#include "NewCommandParams.h"
namespace CML{


NewCommandParams::NewCommandParams(const char *dna, const std::string &name):m_dna(dna),m_name(name)
{
    static size_t numDefault = 1;
    if(name.empty())
    {
        m_name += "seq";
        m_name += char('0' + numDefault);
        ++numDefault;
    }

}

}