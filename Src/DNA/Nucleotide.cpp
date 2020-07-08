//
// Created by a on 7/5/20.
//
#include "Nucleotide.h"
#include "../Utils/isConsistOf.h"
#include <iostream>
const char* Nucleotide::s_baseDna = "ACGT";

Nucleotide::Nucleotide(char nuc)
{
    if(!isConsistOf(nuc, s_baseDna))
        throw std::invalid_argument("invalid_baseDna");
    m_nucleotide = nuc;
}


Nucleotide Nucleotide::getBasePair() const
{
    switch (m_nucleotide)
    {
        case 'A':return 'T';
        case 'C':return 'G';
        case 'G':return 'C';
        case 'T':return 'A';
    }
    return -1;
}

const Nucleotide& Nucleotide::operator=(const Nucleotide &otherNuc)
{
    m_nucleotide = otherNuc.m_nucleotide;
    return *this;
}

bool Nucleotide::operator==(const Nucleotide &otherNuc)const
{
    return m_nucleotide == otherNuc.m_nucleotide;
}

bool Nucleotide::operator!=(const Nucleotide &otherNuc) const {
    return m_nucleotide != otherNuc.m_nucleotide;
}

