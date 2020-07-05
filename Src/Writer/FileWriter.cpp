//
// Created by a on 6/30/20.
//

#include <fstream>
#include "FileWriter.h"
#include "../Exception/MyException.h"
void FileWriter::write(const char *data)const
{
    std::ofstream file(m_fileName);

    std::string line;
    if(!file.is_open())
        throw MyException("Faild_OpenFile");

    file << data;
    file.close();
}

FileWriter::FileWriter(const char *fileName):m_fileName(fileName){}
