#ifndef DNAANALYZERPROJECT_IDNADATA_H
#define DNAANALYZERPROJECT_IDNADATA_H

#include <cstddef>
#include <string>
#include "DNAMetaData.h"
//#include "DNAHashTable.h"
class IDNAData
{
public:
    static IDNAData& getDNAData();
    virtual ~IDNAData(){}
    virtual void insert(const DNAMetaData &metaData)=0;
    virtual const DNAMetaData & find(const std::string& name)const=0;
    virtual const DNAMetaData& find(size_t _id)const=0;
    virtual size_t getId(const std::string& name)const=0;
};


#endif //DNAANALYZERPROJECT_IDNADATA_H
