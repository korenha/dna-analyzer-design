#ifndef DNAANALYZERPROJECT_DNAMETADATA_H
#define DNAANALYZERPROJECT_DNAMETADATA_H
#include "Status.h"
#include<string>
#include "DnaSequence.h"
class DNAMetaData
{
public:
    DNAMetaData(const IReader& reader, const std::string &name);
   // const DNAMetaData& operator=(const DNAMetaData& otherDnaSeq){m_dnaSequence = otherDnaSeq.m_dnaSequence;}
   /* BaseDNA& operator[](size_t index)const{ return m_dnaSequence[index];}
    size_t getLength()const{ return m_dnaSequence.getLength();}
    DnaSequence slice(size_t start,size_t end)const{ return m_dnaSequence.slice(start,end);}
    DnaSequence getPairedDna()const{ return m_dnaSequence.getPairedDna();}
    size_t find(const DnaSequence& subSeq,size_t index=0)const { return m_dnaSequence.find(subSeq,index);}
    size_t count(const DnaSequence& subSeq)const{ return m_dnaSequence.count(subSeq);}
    std::vector<size_t >findAllSubSeq(const DnaSequence& subSeq)const{ return m_dnaSequence.findAllSubSeq(subSeq);}
    std::vector<DnaSequence> findConsensusSequences()const{ return m_dnaSequence.findConsensusSequences();}
    void writerToFile(const IWriter& file){ return m_dnaSequence.writerToFile(file);}*/
    operator const DnaSequence&()const { return m_dnaSequence;}
    std::string getName()const{ return m_name;}
    const char* getStatus()const{return m_status.get();}
    const DnaSequence& getDNASeq()const{ return m_dnaSequence;}

private:
    DnaSequence m_dnaSequence;
    Status m_status;
    std::string m_name;
};


#endif //DNAANALYZERPROJECT_DNAMETADATA_H
