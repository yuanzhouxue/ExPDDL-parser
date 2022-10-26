#ifndef _ACTION_HH_
#define _ACTION_HH_

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "predicate.hh"

enum class LiteralState { POSITIVE, NEGATIVE, UNKNOWN, KNOWN };

std::string to_string(LiteralState s);

using StringList = std::vector<std::string>;
using TypeDict = std::unordered_map<std::string, std::string>;

using PredicateList = std::vector<Predicate *>;
using ParameterList = std::pair<StringList *, TypeDict *>;
using PreconditionList = std::vector<std::pair<Predicate *, LiteralState> *>;
using EffectList = std::vector<std::pair<Predicate *, LiteralState> *>;

class Action {
   public:
    Action(const std::string &name, const ParameterList *params,
           const PreconditionList *precond, const EffectList *effects);

    virtual ~Action();

    friend std::ostream &operator<<(std::ostream &out, const Action &action);

   private:
    std::string _name;
    const StringList *_params;
    const TypeDict *_types;
    const PreconditionList *_precond;
    const EffectList *_effects;
};

#endif  // _ACTION_HH_
