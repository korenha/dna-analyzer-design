#ifndef DNAANALYZERPROJECT_CONSULWRITER_H
#define DNAANALYZERPROJECT_CONSULWRITER_H


#include "IWriter.h"

class ConsulWriter: public IWriter
{
    void write(const char* output)const;
};


#endif //DNAANALYZERPROJECT_CONSULWRITER_H
