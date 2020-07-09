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
    Manager manager(new FileReader("fileReader.txt"),new FileWriter("result.txt",0));
    manager.doAction();
    return 0;
}