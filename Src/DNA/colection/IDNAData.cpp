#include "IDNAData.h"
#include "hashTable/DNAHashTable.h"
IDNAData& IDNAData::getDNAData()
{
    return DNAHashTable::getDNAData();
}


