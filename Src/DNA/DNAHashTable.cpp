#include "DNAHashTable.h"

void DNAHashTable::insert(const DNAMetaData &metaData)
{
    mapByNameToId.insert(pair<std::string,size_t >(metaData.getName(),id));
    DNAData.insert(pair<size_t ,DNAMetaData >(id,metaData));
    ++id;
}

size_t DNAHashTable::find(const std::string &name)const {
    return 0;
}


IDNAData&  DNAHashTable::getDNAData() {
    static DNAHashTable data;
    return data;
}

//const DNAMetaData &DNAHashTable::find(size_t _id)const
//{
    //return DNAMetaData();
//}

