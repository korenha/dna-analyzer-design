#include "DnaSequence.h"
#include "../Exception/MyException.h"
#include "../Utils/isConsistOf.h"
#include <string.h>
#include <iostream>
#include "../Reader/IReader.h"
#include "../Writer/IWriter.h"

static bool dnaSeqCmp(const DnaSequence& dna1,const DnaSequence& dna2);



void DnaSequence::initDna(const char *dna)
{
    m_dnaSeq = new BaseDNA[strlen(dna) + 1];
    lengthDna = strlen(dna);
    for (size_t i = 0; i < lengthDna; ++i)
    {
        m_dnaSeq[i] = dna[i];
    }
}

void DnaSequence::initDna(const DnaSequence& dna)
{
    m_dnaSeq = new BaseDNA[dna.lengthDna + 1];
    lengthDna = dna.lengthDna;
    for (size_t i = 0; i < lengthDna; ++i)
    {
        m_dnaSeq[i] = dna[i];
    }
}

DnaSequence::DnaSequence(const char* dnaSeq)
{
    if(!isConsistOf(dnaSeq, BaseDNA::s_baseDna))
        throw std::invalid_argument("Not consist of baseDna");
    initDna(dnaSeq);
}

DnaSequence::DnaSequence(const IReader& dnaSeq)
{
    std::string dna = dnaSeq.read();
    if(!isConsistOf(dna.c_str(), BaseDNA::s_baseDna))
        throw std::invalid_argument("Not consist of baseDna");
    initDna(dna.c_str());
}

DnaSequence::DnaSequence(const std::string &dnaSeq)
{
    if(!isConsistOf(dnaSeq.c_str(), BaseDNA::s_baseDna))
        throw std::invalid_argument("Not consist of baseDna");
    initDna(dnaSeq.c_str());
}

DnaSequence::DnaSequence(const DnaSequence &otherDna)
{
    initDna(otherDna);
}

DnaSequence::~DnaSequence()
{
    delete[] m_dnaSeq;
}

DnaSequence::DnaSequence(size_t length)
{
    m_dnaSeq = new BaseDNA[length];
    lengthDna = length;
}

BaseDNA& DnaSequence::operator[](size_t index) const
{
    if(index > lengthDna)
        throw std::invalid_argument("Invalid_index");
    return m_dnaSeq[index];
}

const DnaSequence& DnaSequence::operator=(const DnaSequence& otherDnaSeq)
{
    if(*this == otherDnaSeq)
        return *this;

    BaseDNA *toDelete = m_dnaSeq;
    try
    {
        initDna(otherDnaSeq);
        delete[] toDelete;
    }
    catch (const std::bad_alloc& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    return *this;

}

size_t DnaSequence::getLength()const
{
    return lengthDna;
}

bool operator==(const DnaSequence& dna1, const DnaSequence& dna2)
{
    return (!dnaSeqCmp(dna1,dna2));

}

DnaSequence DnaSequence::slice(size_t start, size_t end)const
{
    if(end <= start)
        return DnaSequence("");

    DnaSequence dnaSlice((end - start));
    for (size_t i = 0; i < end - start; ++i)
    {
        dnaSlice[i] = m_dnaSeq[i + start];
    }
    return dnaSlice;
}

DnaSequence DnaSequence::getPairedDna() const
{
    DnaSequence dnaPaired(lengthDna);
    for (size_t i = 0; i < lengthDna; ++i)
    {
        dnaPaired[i] = this->m_dnaSeq[(lengthDna-i -1)].getBasePair();

    }
    return dnaPaired;
}

bool operator!=(const DnaSequence& dna1, const DnaSequence& dna2)
{
    return (dnaSeqCmp(dna1,dna2) != 0);
}

size_t DnaSequence::find(const DnaSequence& subSeq,size_t index) const//index is default to 0
{
    std::string seq=(const char*)m_dnaSeq;
    return seq.find((const char*)subSeq.m_dnaSeq,index);
}

size_t DnaSequence::count(const DnaSequence &subSeq)const
{
    size_t count = 0,indexFound;
    indexFound = find(subSeq);
    DnaSequence dna = *this;
    while(indexFound != std::string::npos)
    {
        count++;
        indexFound = find(subSeq,indexFound + 1);
    }
    return count;
}

std::vector<size_t > DnaSequence::findAllSubSeq(const DnaSequence &subSeq)const
{
    std::vector<size_t >seqFoundIndexes;
    size_t indexFound = find(subSeq);
    while(indexFound != std::string::npos)
    {
        seqFoundIndexes.push_back(indexFound);
        indexFound = find(subSeq,indexFound + 1);
    }
    return seqFoundIndexes;
}

std::ostream &operator<<(std::ostream &out,const DnaSequence &dna)
{
    for (size_t i = 0; i < dna.getLength(); ++i)
    {
        out<<dna[i];
    }
    return out;
}



void DnaSequence::addConsensus(std::vector<DnaSequence> &updateVector, size_t indexStart, const std::vector<size_t >& end)const
{
    for (size_t j = end.size(); j > 0 && indexStart < end[j-1]; --j)
    {
        if((end[j-1] - indexStart)%3 == 0)
        {
            updateVector.push_back(this->slice(indexStart,end[j-1] + 3));
        }
    }
}

std::vector<DnaSequence> DnaSequence::findConsensusSequences()const
{
    std::vector<size_t > findATG = findAllSubSeq("ATG");
    std::vector<size_t > findTAG = findAllSubSeq("TAG");
    std::vector<size_t > findTAA = findAllSubSeq("TAA");
    std::vector<size_t > findTGA = findAllSubSeq("TGA");
    std::vector<size_t > findAll ;
    std::vector<DnaSequence> consensusSequences;

    for (size_t i = 0; i < findATG.size(); ++i)
    {
        addConsensus(consensusSequences, findATG[i], findTAA);
        addConsensus(consensusSequences, findATG[i], findTAG);
        addConsensus(consensusSequences, findATG[i], findTGA);
    }

    return consensusSequences;

}

void DnaSequence::writerToFile(const IWriter &file)
{
    file.write((const char*)m_dnaSeq);
}

static bool dnaSeqCmp(const DnaSequence &dna1, const DnaSequence &dna2)
{
    size_t i=0;

    while(i < dna1.getLength()-1 && i < dna2.getLength() && dna1[i] == dna2[i])
    {
        i++;
    }

    return dna1[i] - dna2[i];
}