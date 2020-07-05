//
// Created by a on 6/30/20.
//

#include "TestFileWriter.h"
#include "../Writer/FileWriter.h"
#include<iostream>
#include<cstring>
#include<exception>

void TestFileWriter::testAll()
{
    std::cout<<"\n------------Start test FileReader-----------\n"<<std::endl;
    testCtor();
    testWrite();
    std::cout<<"\n------------End test FileReader-----------\n"<<std::endl;

}

void TestFileWriter::testCtor()
{
    std::string problem;
    try
    {
        const char* fileName = "test.text";
        FileWriter file(fileName);
        if(0 != strcmp(file.m_fileName,fileName))
            problem += "check 1";


    }
    catch (const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }
    if(!problem.empty())
        std::cout<<"  Error: FileWriter::FileWriter(const char *fileName) is not ok\n\t\t in checks: "<<problem<<std::endl;
    else
        std::cout<<"\tFileWriter::FileWriter(const char *fileName) is ok"<<std::endl;
}

void TestFileWriter::testWrite()
{
    std::string problem;
    try
    {
        const char *fileName = "test.text";
        std::string str,text = "TATTTTGGCCAATTTTT";
        FileWriter file(fileName);
        file.write("ABCDEFGHIJKLMNOP");

    }
    catch (const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }

    if(!problem.empty())
        std::cout<<"  Error: void FileWriter::write(const char *data) is not ok\n\t\t in checks: "<<problem<<std::endl;
    else
        std::cout<<"\tvoid FileWriter::write(const char *data) is ok"<<std::endl;
}
