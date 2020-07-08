//
// Created by a on 6/30/20.
//

#ifndef DNA_TESTFILEREADER_H
#define DNA_TESTFILEREADER_H


#include <fstream>
#include "../../Reader/fileReader/FileReader.h"
#include "../../Exception/MyException.h"

class TestFileReader
{
public:
    static void testAll();
    static void testCtor();
    static void testRead();
};




#endif //DNA_TESTFILEREADER_H
