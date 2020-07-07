#ifndef DNAANALYZERPROJECT_DNAHASHTABLE_H
#define DNAANALYZERPROJECT_DNAHASHTABLE_H
#include <iostream>
#include <map>
#include "DNAMetaData.h"
#include "IDNAData.h"
#include <hash_map>
using std::pair;
using std::map;
using __gnu_cxx::hash_map;
class DNAHashTable:public IDNAData
{
public:

    static IDNAData& getDNAData();
    //static const DNAHashTable  DNACollection;
    void insert(const DNAMetaData &metaData);
    const DNAMetaData & find(const std::string& name)const;
    const DNAMetaData& find(size_t _id)const;
    size_t getId(const std::string& name)const;
    //add functions
    //void deleteDNa();
private:
    friend class DNAData;
    size_t id;
    map<std::string ,size_t > mapByNameToId;
    //__gnu_cxx::hash_map<size_t ,DNAMetaData > DNAData;
    std::map<size_t ,DNAMetaData > DNAData;
    DNAHashTable():id(1){}
    DNAHashTable(DNAHashTable&){}

};


#endif //DNAANALYZERPROJECT_DNAHASHTABLE_H
