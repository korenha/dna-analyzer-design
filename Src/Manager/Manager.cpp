#include "Manager.h"
#include <iostream>
#include "Terminal.h"

void Manager::doAction()
{
    std::cout<<"|--------Start Program-------------|"<<std::endl;
    Terminal::run(m_reader,m_writer);
    std::cout<<"|--------End Program-------------|"<<std::endl;
}
