//
// Created by a on 6/30/20.
//

#include <fstream>
#include "FileWriter.h"
#include "../../Exception/MyException.h"
void FileWriter::write(const char *data)const
{
    const char* name = m_fileName.c_str();
    std::ofstream file;

    if(!m_renew)
    {
        file.open(name,std::ios::app);
    } else
    {
        file.open(name);
    }
    if(!file.is_open())
        throw MyException("Faild_OpenFile");

    file << data;

    file.close();
}

FileWriter::FileWriter(const std::string &fileName,bool renew) : m_fileName(fileName),m_renew(renew){}

void FileWriter::clear() const
{
    std::ofstream file;
    const char* name = m_fileName.c_str();
    file.open(name);
    file.clear();
    file.close();
}
