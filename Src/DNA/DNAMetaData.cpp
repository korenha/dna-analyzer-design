//
// Created by a on 7/5/20.
//

#include "DNAMetaData.h"

DNAMetaData::DNAMetaData(const IReader& reader, const std::string &name)
        : m_dnaSequence(reader),m_name(name)
{}


