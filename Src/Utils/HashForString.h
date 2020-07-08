#ifndef DNAANALYZERPROJECT_HASHFORSTRING_H
#define DNAANALYZERPROJECT_HASHFORSTRING_H

#include <string>
#include <hash_map>
namespace __gnu_cxx {
    template <> struct hash<std::string> {
        size_t operator()(std::string const & s) const {
            hash<const char *> h;
            return h(s.c_str());
        }
    };
}
#endif //DNAANALYZERPROJECT_HASHFORSTRING_H
