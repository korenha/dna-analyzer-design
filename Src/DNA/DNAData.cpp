#include "DNAData.h"
#include "DNAHashTable.h"
DNAHashTable *DNAData::getDNAData()
{
    static DNAHashTable data;
    return &data;
}
