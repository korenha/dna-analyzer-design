#ifndef DNAANALYZERPROJECT_DNAHASHTABLE_H
#define DNAANALYZERPROJECT_DNAHASHTABLE_H
#include <iostream>
#include <map>
#include "DNAMetaData.h"
using std::pair;
using std::map;

//using __gnu_cxx::hash_map;
class DNAHashTable
{
public:
    DNAHashTable():id(1){}
    void insert(const IReader &reader, const std::string &name);
    size_t find(const std::string& name)const;
    const DNAMetaData& find(size_t _id)const;
    //add functions
    //void deleteDNa();
private:
    size_t id;
    map<std::string ,size_t > mapByNameToId;
    map<size_t ,DNAMetaData > DNAData;


};


#endif //DNAANALYZERPROJECT_DNAHASHTABLE_H
