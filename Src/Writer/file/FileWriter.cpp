//
// Created by a on 6/30/20.
//

#include <fstream>
#include "FileWriter.h"
#include "../../Exception/MyException.h"
void FileWriter::write(const char *data)const
{
    const char* name = m_fileName.c_str();
    std::ofstream file(name);

    std::string line;
    if(!file.is_open())
        throw MyException("Faild_OpenFile");

    file << data;
    file.close();
}

FileWriter::FileWriter(const std::string &fileName) : m_fileName((fileName)){}
