#include <iostream>
#include "Test/TestDnaSeq.h"
#include "Test/TestFileReader.h"
#include "Test/TestFileWriter.h"


int main()
{
    TestDnaSeq::test();
    TestFileReader::testAll();
    TestFileWriter::testAll();
    return 0;
}