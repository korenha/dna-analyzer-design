#include <iostream>
#include "Test/DNASequence/TestDnaSeq.h"
#include "Test/fileReader/TestFileReader.h"
#include "Test/fileWriter/TestFileWriter.h"
#include "Manager/mainManager/Manager.h"


int main()
{
   // TestDnaSeq::test();
   // TestFileReader::testAll();
    //TestFileWriter::testAll();
    Manager manager;
    manager.doAction();
    return 0;
}