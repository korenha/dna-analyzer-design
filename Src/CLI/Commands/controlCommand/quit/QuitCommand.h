#ifndef DNAANALYZERPROJECT_QUITCOMMAND_H
#define DNAANALYZERPROJECT_QUITCOMMAND_H

#include "../IControlCommand.h"
#include "../../../CommandsParams/Params.h"
#include "../../../../Reader/IReader.h"
#include "../../../../Writer/IWriter.h"

namespace CLI
{

    class QuitException{};
    class QuitCommand : public IControlCommand
    {
    public:
        QuitCommand(const IReader* const reader,const IWriter* writer):m_reader(reader),m_writer(writer){}
        std::string run(Params *params);

    private:
        const IReader* const m_reader;
        const IWriter* const m_writer;
    };

}
#endif //DNAANALYZERPROJECT_QUITCOMMAND_H
