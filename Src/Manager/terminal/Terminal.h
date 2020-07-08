//
// Created by a on 7/7/20.
//

#ifndef DNAANALYZERPROJECT_TERMINAL_H
#define DNAANALYZERPROJECT_TERMINAL_H


#include "../../Reader/IReader.h"
#include "../../Writer/IWriter.h"

class Terminal
{
public:
    static void run(const IReader* readFrom,const IWriter* writeTo);
};


#endif //DNAANALYZERPROJECT_TERMINAL_H
