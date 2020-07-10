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
    static void run(const IReader *const readFrom, const IWriter *const writeTo, bool writeInput = false);
};


#endif //DNAANALYZERPROJECT_TERMINAL_H
