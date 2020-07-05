#include "DNAHashTable.h"

void DNAHashTable::insert(const IReader &reader, const std::string &name)
{
    mapByNameToId.insert(pair<std::string,size_t >(name,id));
    DNAData.insert(pair<size_t ,DNAMetaData >(id,DNAMetaData(reader,name)));
    ++id;
}

size_t DNAHashTable::find(const std::string &name)const {
    return 0;
}

//const DNAMetaData &DNAHashTable::find(size_t _id)const
//{
    //return DNAMetaData();
//}

