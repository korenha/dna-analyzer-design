//
// Created by a on 6/1/20.
//
#ifndef DNASEQUENCE_DNASEQUENCE_H
#define DNASEQUENCE_DNASEQUENCE_H

#include <string>
#include <vector>
#include "Nucleotide.h"
class IReader;
class IWriter;

class DNAfile;
typedef Nucleotide BaseDNA;

class DnaSequence
{
private:


public:
    DnaSequence(const char* dnaSeq);
    DnaSequence(const std::string& dnaSeq);
    DnaSequence(const IReader& dnaSeq);
    DnaSequence(const DnaSequence& otherDna);
    ~DnaSequence();
    const DnaSequence& operator=(const DnaSequence& otherDnaSeq);
    BaseDNA& operator[](size_t index)const;
    size_t getLength()const;
    DnaSequence slice(size_t start,size_t end)const;
    DnaSequence getPairedDna()const;
    size_t find(const DnaSequence& subSeq,size_t index=0)const ;
    size_t count(const DnaSequence& subSeq)const;
    std::vector<size_t >findAllSubSeq(const DnaSequence& subSeq)const;
    std::vector<DnaSequence> findConsensusSequences()const;
    void writerToFile(const IWriter& file);



private:
    BaseDNA* m_dnaSeq;
    size_t lengthDna;
    friend class TestDnaSeq;
    DnaSequence(size_t length);
    void addConsensus(std::vector<DnaSequence> &updateVector, size_t indexStart, const std::vector<size_t >& end)const;
    void initDna(const char* dna);
    void initDna(const DnaSequence& dna);

};

std::ostream &operator<<(std::ostream &out,const DnaSequence &dna);


bool operator==(const DnaSequence& dna1, const DnaSequence& dna2);

bool operator!=(const DnaSequence& dna1, const DnaSequence& dna2);


#endif //DNASEQUENCE_DNASEQUENCE_H
