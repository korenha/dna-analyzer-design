//
// Created by a on 6/30/20.
//

#ifndef DNA_FILEWRITER_H
#define DNA_FILEWRITER_H


#include "IWriter.h"

class FileWriter: public IWriter
{
public:
    FileWriter(const char* fileName);
    void write(const char* data)const;

private:
    const char *m_fileName;
    friend class TestFileWriter;
};


#endif //DNA_FILEWRITER_H
