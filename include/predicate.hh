#ifndef __PREDICATE_HH__
#define __PREDICATE_HH__

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using StringList = std::vector<std::string>;
using TypeDict = std::unordered_map<std::string, std::string>;
using ArgumentList = std::pair<StringList*, TypeDict*>;

class Predicate {
   public:
    Predicate(std::string name, ArgumentList* args);
    virtual ~Predicate();

    friend std::ostream& operator<<(std::ostream& out,
                                    const Predicate& predicate);

    std::string _name;
    StringList* _args;
    TypeDict* _types;
};

#endif
