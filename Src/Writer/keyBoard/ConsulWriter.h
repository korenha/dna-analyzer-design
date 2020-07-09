#ifndef DNAANALYZERPROJECT_CONSULWRITER_H
#define DNAANALYZERPROJECT_CONSULWRITER_H


#include "../IWriter.h"

class ConsulWriter: public IWriter
{
public:
    void write(const char* output)const;
    virtual void clear()const{}
};


#endif //DNAANALYZERPROJECT_CONSULWRITER_H
