#ifndef DNAANALYZERPROJECT_MANAGER_H
#define DNAANALYZERPROJECT_MANAGER_H


#include "../Reader/IReader.h"
#include "../Writer/IWriter.h"
#include "../Reader/ConsulReader.h"
#include "../Writer/ConsulWriter.h"

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
    Manager(IReader* reader = new ConsulReader(),IWriter* writer = new ConsulWriter()):m_reader(reader),m_writer(writer){}
    ~Manager(){delete m_reader;delete m_writer;}


private:
    IReader* m_reader;
    IWriter* m_writer;
};


#endif //DNAANALYZERPROJECT_MANAGER_H
