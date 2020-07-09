#include <fstream>
#include <iostream>
#include "FileReader.h"
#include "../../Exception/MyException.h"
FileReader::FileReader(const char *fileName) : m_fileName(fileName)
{
    std::ifstream file(fileName,std::ios::in);
    if(!file.is_open())
        throw MyException("Failed open file");
    file.close();
}

std::string FileReader::read()const
{
    std::ifstream file(m_fileName,std::ios::out);
    if(!file.is_open())
        throw MyException("Faild_OpenFile");

    static size_t position = 0;
    file.seekg(position,std::ios_base::beg);
    std::string text;
    std::getline(file,text);
    position = file.tellg();
    //file >> text;
    //std::getline(file, text);
    file.close();
    return text;
}


