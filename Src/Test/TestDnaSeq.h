#ifndef __TESTDNASEQ_H__
#define __TESTDNASEQ_H__


#include "../DNA/DnaSequence.h"

class TestDnaSeq
{
public:
//    TestDnaSeq();
    static void test();
    static void testCtorByConstChar();
    static void testCtorByString();
    static void testCopyCtor();
    static void testIsValid();
    static void testAssigmentOperator();
    static void testOperator();//[]
    static void testGetLength();
    static void testSlice();
    static void testGetPairedDna();
    static void testFind();
    static void testCount();
    static void testFindAll();
    static void testFindConsensusSequences();





};


#endif //__TESTDNASEQ_H__
