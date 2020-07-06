#ifndef DNAANALYZERPROJECT_CONSULREADER_H
#define DNAANALYZERPROJECT_CONSULREADER_H


#include "IReader.h"

class ConsulReader: public IReader
{
public:
    std::string read();

};


#endif //DNAANALYZERPROJECT_CONSULREADER_H
