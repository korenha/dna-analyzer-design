#ifndef DNAANALYZERPROJECT_MANAGER_H
#define DNAANALYZERPROJECT_MANAGER_H


#include "../../Reader/IReader.h"
#include "../../Writer/IWriter.h"
#include "../../Reader/keyBoard/ConsulReader.h"
#include "../../Writer/keyBoard/ConsulWriter.h"

/*class MenagerWriterReader{
public:
    MenagerWriterReader(IReader* reader,IWriter* writer):m_reader(reader),m_writer(writer){}
    IReader* const getReader(){ return m_reader;}
    IReader* const getWriter(){ return m_reader;}

private:
    IReader* m_reader;
    IWriter* m_writer;
};*/

class Manager
{
public:
    void doAction();
    Manager(const IReader *const reader, const IWriter *const writer, bool writeInput = false): m_reader(reader), m_writer(writer), writeInput(writeInput){writer->clear();}
    ~Manager(){}



private:
    const IReader* const m_reader;
    const IWriter* const m_writer;
    bool writeInput;
};


#endif //DNAANALYZERPROJECT_MANAGER_H
