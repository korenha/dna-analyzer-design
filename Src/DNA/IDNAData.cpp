#include "IDNAData.h"
#include "DNAHashTable.h"
IDNAData& IDNAData::getDNAData()
{
    return DNAHashTable::getDNAData();
}

