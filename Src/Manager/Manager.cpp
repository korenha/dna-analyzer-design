#include "Manager.h"
#include <iostream>
#include "Terminal.h"

void Manager::doAction()
{
    std::cout<<"\n|--------Start Program-------------|\n"<<std::endl;
    Terminal::run(m_reader,m_writer);
    std::cout<<"\n\n|--------End Program-------------|"<<std::endl;
}
