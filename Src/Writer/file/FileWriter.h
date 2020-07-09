//
// Created by a on 6/30/20.
//

#ifndef DNA_FILEWRITER_H
#define DNA_FILEWRITER_H

#include <string>

#include "../IWriter.h"

class FileWriter: public IWriter
{
public:
    FileWriter(const std::string &fileName,bool renew = true);
    void write(const char* data)const;
    virtual void clear()const;

private:
    std::string m_fileName;
    bool m_renew;
    friend class TestFileWriter;
};


#endif //DNA_FILEWRITER_H
