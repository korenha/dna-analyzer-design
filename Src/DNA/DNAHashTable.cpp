#include "DNAHashTable.h"

void DNAHashTable::insert(const DNAMetaData &metaData)
{
    //mapByNameToId.insert(id));
    mapByNameToId.insert(pair<std::string,size_t >(metaData.getName(),id));
    DNAData.insert(pair<size_t ,DNAMetaData >(id,metaData));
    ++id;
}

const DNAMetaData & DNAHashTable::find(const std::string &name)const {
    return DNAData.find(getId(name))->second;
}


IDNAData&  DNAHashTable::getDNAData() {
    static DNAHashTable data;
    return data;
}

const DNAMetaData &DNAHashTable::find(size_t _id) const {
    return DNAData.find(_id)->second;
}

size_t DNAHashTable::getId(const std::string &name)const {
    return mapByNameToId.find(name)->second;
}

//const DNAMetaData &DNAHashTable::find(size_t _id)const
//{
    //return DNAMetaData();
//}

