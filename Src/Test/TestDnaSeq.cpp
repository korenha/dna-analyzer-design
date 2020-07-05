//
// Created by a on 6/2/20.
//
#include <string>
#include "TestDnaSeq.h"
#include "../GlobalFunction/globalFunctions.h"
#include <iostream>
#include <string.h>

void TestDnaSeq::test()
{
    std::cout<<"\n------------Start test DnaSequence class----------\n"<<std::endl;
    testIsValid();
    testCtorByConstChar();
    testCtorByString();
    testCopyCtor();
    testAssigmentOperator();
    testOperator();//[]
    testGetLength();
    testSlice();
    testGetPairedDna();
    testFind();
    testCount();
    testFindAll();
    testFindConsensusSequences();
    std::cout<<"\n------------End test DnaSequence class----------"<<std::endl;

}

void TestDnaSeq::testIsValid()
{
    std::string problems;
    if(!(isConsistOf("AAAGGGTGTCCATTGTA",Nucleotide::s_baseDna)))
        problems += "1, ";
    if(isConsistOf("AAAGGGcTTCCATTGTA",Nucleotide::s_baseDna))
        problems += "2, ";

    if(isConsistOf('\0',Nucleotide::s_baseDna))
        problems += "3";
    if(!problems.empty())
        std::cout<<"\tError: isValidSeq()\n: \t\tin checks: "<<problems<<std::endl;
    else
        std::cout<<"\tisValidSeq() is ok"<<std::endl;
}

void TestDnaSeq::testCtorByConstChar()
{
    const char* dnaSeq="AGACTTAGA";
    std::string problems;
    try
    {
        DnaSequence dna1(dnaSeq);
        if(dna1 != dnaSeq)
            problems += "1, ";
    }

    catch(const std::exception& e)/*2*/
    {
        problems += "2, ";
    }

    try
    {
        DnaSequence dna1("AAAc");
        problems += "3";
    }

    catch(const std::exception& e)/*2*/
    {
    }

    if(!problems.empty())
        std::cout<<"\tError: DnaSequence::DnaSequence(const char* dnaSeq)\n: \t\tin checks: "<<problems<<std::endl;
    else
        std::cout<<"\tDnaSequence::DnaSequence(const char* dnaSeq) is ok"<<std::endl;
}

void TestDnaSeq::testCtorByString()
{
    std::string dnaSeq="AGACTTAGA";
    std::string problems;
    try
    {
        DnaSequence dna1(dnaSeq);
        if(dna1 != dnaSeq.c_str())
            problems += "1, ";
    }

    catch(const std::exception& e)/*2*/
    {
        problems += "2, ";
    }

    try
    {
        dnaSeq = "AAAc";
        DnaSequence dna1(dnaSeq);
        problems += "3";
    }

    catch(const std::exception& e)/*2*/
    {}

    if(!problems.empty())
        std::cout<<"\tError: DnaSequence::DnaSequence(const std::string& dnaSeq)\n: \t\tin checks: "<<problems<<std::endl;
    else
    {
        std::cout<<"\tDnaSequence::DnaSequence(const std::string& dnaSeq) is ok"<<std::endl;
    }
}

void TestDnaSeq::testCopyCtor()
{
    DnaSequence dnaSeq("AGACTTAGA");
    std::string problems;
    DnaSequence dna1 = dnaSeq;
    if(dna1 != dnaSeq)
        problems += "1, ";
    if(!problems.empty())
        std::cout<<"\tError: DnaSequence::DnaSequence(const std::DnaSequence& dnaSeq)\n: \t\tin checks: "<<problems<<std::endl;
    else
    {
        std::cout<<"\tDnaSequence::DnaSequence(const std::DnaSequence& dnaSeq) is ok"<<std::endl;
    }
}

void TestDnaSeq::testAssigmentOperator()
{
    try
    {
        DnaSequence dna1("AAAAAAA");
        std::string problems;
        DnaSequence dna2("ACGGATT");

        dna1 = dna2;
        if(dna1 != dna2)
            problems += "1, ";

        dna1 = "ACGACG";
        if(dna1 != "ACGACG")
            problems += "2, ";

        std::string str = "AAACGA";
        dna1 = str;
        if(dna1 != str.c_str())
            problems += "3";

        if(!problems.empty())
            std::cout<<"\tError: const DnaSequence& DnaSequence::operator=(const DnaSequence& otherDnaSeq)\n: \t\tin checks: "<<problems<<std::endl;
        else
        {
            std::cout<<"\tconst DnaSequence& DnaSequence::operator=(const DnaSequence& otherDnaSeq) is ok"<<std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }

}

void TestDnaSeq::testOperator()//[]
{
    try
    {
        DnaSequence dnaSeq("ATGC");
        std::string problems;
        if(dnaSeq.m_dnaSeq[3] != dnaSeq[3])
            problems += "1, ";

        try
        {

            std::cout<<dnaSeq[10];
            problems += "2";

        }
        catch(const std::exception& e)
        {
        }

        try
        {
            char x = dnaSeq[1];
            if (x != 'T')
                problems += "4, ";

            dnaSeq[0] = 'C';
            if((char)dnaSeq[0] != 'C')
                problems += "5,";


        }
        catch(const std::exception& e)
        {
            problems += "3";
        }



        if(!problems.empty())
            std::cout<<"\tError: const char& DnaSequence::operator[](size_t index)\n: \t\tin checks: "<<problems<<std::endl;
        else
        {
            std::cout<<"\tconst char& DnaSequence::operator[](size_t index) is ok"<<std::endl;
        }
    }

    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }

}

void TestDnaSeq::testGetLength()
{
    try
    {
        const char *toInit = "AAAAAGGGGTTTTCCC";
        DnaSequence dnaSeq(toInit);
        std::string problems;
        if(strlen(toInit) != dnaSeq.getLength())
            problems += "1, ";
        if(!problems.empty())
            std::cout<<"\tError: size_t DnaSequence::getLength()\n: \t\tin checks: "<<problems<<std::endl;
        else
        {
            std::cout<<"\tsize_t DnaSequence::getLength() is ok"<<std::endl;
        }
    }

    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }}

void TestDnaSeq::testSlice()
{
    try
    {
        std::string problems;
        const char* initDna = "AAAAAACCCCCGGGGGTTTTT";
        DnaSequence x("");
        DnaSequence dna(initDna);
        DnaSequence dnaSlice = dna.slice(2,7);
        if(dnaSlice != "AAAAC")
            problems += "1, ";
        dnaSlice = dna.slice(7,2);
        if(dnaSlice != "")
            problems += "2, ";

        if(!problems.empty())
            std::cout<<"\tError: DnaSequence DnaSequence::slice(size_t start, size_t end)const\n: \t\tin checks: "<<problems<<std::endl;

        else
        {
            std::cout<<"\tDnaSequence DnaSequence::slice(size_t start, size_t end)const is ok"<<std::endl;
        }
    }

    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }
}

void TestDnaSeq::testGetPairedDna()
{
    try
    {
        DnaSequence dna("AAAGGGTTTAAGTGTC"),dna1("GACACTTAAACCCTTT");
        DnaSequence pair = dna.getPairedDna();
        std::string problems;
        if(dna.getPairedDna() != dna1)
            problems += "1, ";
        if(!problems.empty())
            std::cout<<"\tError: DnaSequence::GetPairedDna()\n: \t\tin checks: "<<problems<<std::endl;
        else
        {
            std::cout<<"\tsize_t DnaSequence::GetPairedDna() is ok"<<std::endl;
        }
    }

    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }
}

void TestDnaSeq::testFind()
{
    try
    {
        DnaSequence dna("AAAGGGTTTAAGTGTC");
        std::string problems;

        if(dna.find("GTT") != 5)
            problems += "1, ";
        if(dna.find("ATAT") != (size_t)-1)
            problems += "2, ";

        if(!problems.empty())
            std::cout<<"\tError: DnaSequence::GetFind(const DnaSequence&)\n: \t\tin checks: "<<problems<<std::endl;

        else
        {
            std::cout<<"\tsize_t DnaSequence::GetFind(const DnaSequence&) is ok"<<std::endl;
        }
    }

    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }

}

void TestDnaSeq::testCount()
{
    try
    {
        DnaSequence dna("AAAGGGTTTAAGTGTCTT");
        std::string problems;

        if(dna.count("TT") != 3)
            problems += "1, ";
        if(dna.count("ATAT") != 0)
            problems += "2, ";

        if(!problems.empty())
            std::cout<<"\tError: DnaSequence::GetCount(const DnaSequence&)\n: \t\tin checks: "<<problems<<std::endl;

        else
        {
            std::cout<<"\tsize_t DnaSequence::GetCount(const DnaSequence&) is ok"<<std::endl;
        }
    }

    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }

}

void TestDnaSeq::testFindAll()
{
    try
    {
        DnaSequence dna("AAAGGGTTTAAGTGTCTT");
        std::string problems;
        std::vector<size_t > founds = dna.findAllSubSeq("TT");

        if(founds.size() != 3)
            problems += "1, ";
        if(dna.findAllSubSeq("ATAT").size() != 0)
            problems += "2, ";

        if(!problems.empty())
            std::cout<<"\tError: DnaSequence::findAllSubSeq(const DnaSequence&)\n: \t\tin checks: "<<problems<<std::endl;

        else
        {
            std::cout<<"\tsize_t DnaSequence::findAllSubSeq(const DnaSequence&) is ok"<<std::endl;
        }
    }

    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }

}

void TestDnaSeq::testFindConsensusSequences()
{
    try
    {
        DnaSequence dna("ATGTAATAGATGAATTAAAAAAAA");
        std::string problems;
        std::vector<DnaSequence > founds = dna.findConsensusSequences();
        if(founds.size() != 4)
            problems += "1, ";

        if(!problems.empty())
            std::cout<<"\tError: vector<DnaSequence> DnaSequence::findConsensusSequences()const\n: \t\tin checks: "<<problems<<std::endl;

        else
        {
            std::cout<<"\tvector<DnaSequence> DnaSequence::findConsensusSequences()const is ok"<<std::endl;
        }
    }

    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }

}