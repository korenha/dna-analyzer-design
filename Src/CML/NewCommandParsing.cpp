#include "NewCommandParsing.h"

namespace CML{

NewCommandParsing::NewCommandParsing(const std::string &params) : m_dna(params)
{
    static size_t numDefault = 1;
  //  const char* param = params;
    m_dna = params;
        m_name += "seq";
        m_name += char('0' + numDefault);
        ++numDefault;
    }

}

