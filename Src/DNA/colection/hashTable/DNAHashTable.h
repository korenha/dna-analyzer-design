#ifndef DNAANALYZERPROJECT_DNAHASHTABLE_H
#define DNAANALYZERPROJECT_DNAHASHTABLE_H
//#pragma warning diagnostic ignored "-Wno-deprecated" //for hash_map
#include <iostream>
#include <map>
#include "../metaData/DNAMetaData.h"
#include "../IDNAData.h"
#include "../../../Utils/HashForString.h"
#include <hash_map>
using std::pair;
using std::map;

class DNAHashTable:public IDNAData
{
public:

    static IDNAData& getDNAData();
    //static const hashTable  DNACollection;
    void insert(const DNAMetaData &metaData);
    const DNAMetaData & find(const std::string& name)const;
    const DNAMetaData& find(size_t _id)const;
    size_t getId(const std::string& name)const;
    //add functions
    //void deleteDNa();
private:
    size_t id;
    typedef __gnu_cxx::hash_map<std::string ,size_t > NameToId;
    typedef __gnu_cxx::hash_map<size_t ,DNAMetaData > MapDna;
    typedef pair<std::string,size_t > NameToIdPair;
    typedef pair<size_t ,DNAMetaData > MapDnaPair;
    NameToId mapByNameToId;
    MapDna DNAData;
    DNAHashTable():id(1){}
    DNAHashTable(DNAHashTable&){}

};


#endif //DNAANALYZERPROJECT_DNAHASHTABLE_H
