#ifndef __IWRITER_H__
#define __IWRITER_H__


class IWriter
{
public:
    virtual void write(const char* data)const=0;
    virtual ~IWriter(){}
};



#endif //__IWRITER_H__
