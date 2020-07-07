#include <iostream>
#include "Test/TestDnaSeq.h"
#include "Test/TestFileReader.h"
#include "Test/TestFileWriter.h"
#include "Manager/Manager.h"


int main()
{
   // TestDnaSeq::test();
   // TestFileReader::testAll();
    //TestFileWriter::testAll();
    Manager manager;
    manager.doAction();
    return 0;
}