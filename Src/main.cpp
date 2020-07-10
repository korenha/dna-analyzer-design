#include <iostream>
#include "Test/DNASequence/TestDnaSeq.h"
#include "Test/fileReader/TestFileReader.h"
#include "Test/fileWriter/TestFileWriter.h"
#include "Manager/mainManager/Manager.h"
#include "Writer/file/FileWriter.h"


int main()
{
   // TestDnaSeq::test();
   // TestFileReader::testAll();
    //TestFileWriter::testAll();
    FileReader readFrom("fileReader.txt");
    FileWriter writTo("result.txt", false);
    Manager manager(&readFrom,&writTo, true);
    manager.doAction();
    return 0;
}