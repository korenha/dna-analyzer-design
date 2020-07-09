#include "Manager.h"
#include <iostream>
#include "../terminal/Terminal.h"

void Manager::doAction()
{
    m_writer->write("\n|--------Start Program-------------|\n\n");
    Terminal::run(m_reader,m_writer);
    m_writer->write("\n\n|--------End Program-------------|\n");
}
