#include <iostream>
#include "ConsulReader.h"


std::string ConsulReader::read() const
{
    std::string m_read;
    std::getline(std::cin,m_read);
    return m_read;
}

