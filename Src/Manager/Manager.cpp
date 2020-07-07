#include "Manager.h"

#include <iostream>
#include "../Exception/MyException.h"
#include "CommandsManager.h"
#include "ParamsManager.h"
#include "../CLI/Params.h"
#include "Terminal.h"
#include <sstream>
#include <vector>



void Manager::doAction()
{
    std::cout<<"|--------Start Program-------------|"<<std::endl;
    Terminal::run(m_reader,m_writer);
    std::cout<<"|--------End Program-------------|"<<std::endl;
}
