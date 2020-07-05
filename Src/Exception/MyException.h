//
// Created by a on 6/2/20.
//

#ifndef DNASEQUENCE_MYEXCEPTION_H
#define DNASEQUENCE_MYEXCEPTION_H

#include <exception>

class MyException: public std::exception
{

public:
    MyException(const char * message);
    virtual const char* what() const throw()
    {
        return m_message;
    }

private:
    const char* m_message;
};


#endif //DNASEQUENCE_MYEXCEPTION_H
