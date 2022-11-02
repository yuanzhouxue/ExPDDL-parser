#ifndef _PROBLEM_HH_
#define _PROBLEM_HH_

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "predicate.hh"
#include "action.hh"

using StringList = std::vector<std::string>;
using Literal = std::pair<Predicate *, LiteralState>;
using LiteralList = std::vector<Literal *>;
using TypeDict      = std::unordered_map<std::string,std::string>;

class Problem {
   public:
    Problem(std::string name, std::string domain);
    virtual ~Problem();

    void set_objects(TypeDict *objects);

    void set_init_state(LiteralList *init);
    void set_goal_state(LiteralList *goal);

    friend std::ostream &operator<<(std::ostream &out, const Problem &problem);

    std::string _name;
    std::string _domain;

    TypeDict *_objects;
    LiteralList *_init;
    LiteralList *_goal;
};

#endif  // _PROBLEM_HH_
