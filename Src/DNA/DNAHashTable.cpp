#include "DNAHashTable.h"
void DNAHashTable::insert(const DNAMetaData &data)
{
    DNAData.insert(pair<size_t,DNAMetaData >(id, data));
    mapByNameToId.insert(pair<std::string,size_t >(data.getName(), id));
    id++;
}

size_t DNAHashTable::find(const std::string &name)
{
    return mapByNameToId.find(name)->second;
}

const DNAMetaData& DNAHashTable::find(size_t _id)
{
    return DNAData.find(_id)->second;
}
