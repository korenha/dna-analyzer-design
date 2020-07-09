#ifndef DNAANALYZERPROJECT_MANAGER_H
#define DNAANALYZERPROJECT_MANAGER_H


#include "../../Reader/IReader.h"
#include "../../Writer/IWriter.h"
#include "../../Reader/keyBoard/ConsulReader.h"
#include "../../Writer/keyBoard/ConsulWriter.h"

class MenagerWriterReader{
public:
    MenagerWriterReader(IReader* reader,IWriter* writer):m_reader(reader),m_writer(writer){}
    IReader* const getReader(){ return m_reader;}
    IReader* const getWriter(){ return m_reader;}

private:
    IReader* m_reader;
    IWriter* m_writer;
};

class Manager
{
public:
    void doAction();
    Manager(IReader* reader = new ConsulReader(),IWriter* writer = new ConsulWriter(),bool writeInput = false):m_reader(reader),m_writer(writer),writeInput(writeInput){writer->clear();}
    ~Manager(){delete m_reader;delete m_writer;}


private:
    IReader* m_reader;
    IWriter* m_writer;
    bool writeInput;
};


#endif //DNAANALYZERPROJECT_MANAGER_H
