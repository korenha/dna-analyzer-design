#ifndef DNAANALYZERPROJECT_NUCLEOTIDE_H
#define DNAANALYZERPROJECT_NUCLEOTIDE_H


class Nucleotide
{
public:
    Nucleotide(){m_nucleotide = '\0';}
    Nucleotide(char nuc);
    const Nucleotide& operator=(const Nucleotide& otherNuc);
    operator char(){ return m_nucleotide; }
    Nucleotide getBasePair()const;
    bool operator==(const Nucleotide& otherNuc)const;
    bool operator!=(const Nucleotide& otherNuc)const;
    static const char* s_baseDna;

private:
    char m_nucleotide;
};



#endif //DNAANALYZERPROJECT_NUCLEOTIDE_H
