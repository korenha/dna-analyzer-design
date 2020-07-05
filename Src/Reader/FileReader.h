//
// Created by a on 6/30/20.
//

#ifndef DNA_FILEREADER_H
#define DNA_FILEREADER_H


#include "IReader.h"

class FileReader: public IReader
{

public:
    FileReader(const char* fileName);
    std::string read()const;

private:
    friend class TestFileReader;
    const char* m_fileName;
};


#endif //DNA_FILEREADER_H
