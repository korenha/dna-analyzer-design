#ifndef DNAANALYZERPROJECT_STRINGREADER_H
#define DNAANALYZERPROJECT_STRINGREADER_H


#include "IReader.h"

class StringReader: public IReader
{
public:
    StringReader(const std::string &data) : m_string(data){}
    std::string read()const;

private:
    std::string m_string;
};


#endif //DNAANALYZERPROJECT_STRINGREADER_H
