//
// Created by a on 6/30/20.
//

#include "TestFileReader.h"
#include "../../Reader/fileReader/FileReader.h"
#include<iostream>
#include<cstring>
#include<exception>

void TestFileReader::testAll()
{
    std::cout<<"\n------------Start test FileReader-----------\n"<<std::endl;
    testCtor();
    testRead();
    std::cout<<"\n------------End test FileReader-----------\n"<<std::endl;

}

void TestFileReader::testCtor()
{
    std::string problem;
    try
    {
        const char* fileName = "Src/Test/DNA.text";
        FileReader file(fileName);
        if(0 != strcmp(file.m_fileName,fileName))
            problem += "check 1";


    }
    catch (const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }
    try
    {
        const char* fileName = "aaaa";
        FileReader file(fileName);
        problem += "check 2";


    }
    catch (const std::exception& e)
    {
    }
    if(!problem.empty())
        std::cout<<"  Error: FileReader(const char* fileName) is not ok\n\t\t in checks: "<<problem<<std::endl;
    else
        std::cout<<"\tFileReader(const char* fileName) is ok"<<std::endl;
}

void TestFileReader::testRead()
{
    std::string problem;
    try
    {
        const char *fileName = "Src/Test/DNA.text";
        std::string str,text = "TATTTTGGCCAATTTTT";
        FileReader file(fileName);
        str = file.read();
        if(str != text)
            problem += "check 1";

    }
    catch (const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }

    if(!problem.empty())
        std::cout<<"  Error: const char *FileReader::read() is not ok\n\t\t in checks: "<<problem<<std::endl;
    else
        std::cout<<"\tconst char *FileReader::read() is ok"<<std::endl;
}
