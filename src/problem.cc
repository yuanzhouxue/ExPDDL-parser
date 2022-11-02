#include <utility>

#include "problem.hh"

using namespace std;

Problem::Problem(string name, string domain)
    : _name(std::move(name)), _domain(std::move(domain)) {}

Problem::~Problem() {
    delete _objects;

    for (auto literal : *_init) {
        delete literal->first;
    }
    delete _init;

    for (auto goal : *_goal) {
        delete goal->first;
    }
    delete _goal;
}

void Problem::set_objects(TypeDict* objects) { _objects = objects; }

void Problem::set_init_state(LiteralList* init) { _init = init; }

void Problem::set_goal_state(LiteralList* goal) { _goal = goal; }

ostream& operator<<(ostream& out, const Problem& problem) {
    out << ">> Problem(name:" << problem._name << ", domain:" << problem._domain
        << ")" << endl;
    out << endl;
    out << "Objects: [";
    for (auto const& object : *problem._objects) {
        out << " " << object.first << "-" << object.second;
    }
    out << " ]" << endl;
    out << endl;
    out << "Init: [" << endl;
    for (auto const& literal : *problem._init) {
        out << to_string(literal->second);
        out << *(literal->first) << endl;
    }
    out << "]" << endl;
    out << endl;
    out << "Goal: [" << endl;
    for (auto const& literal : *problem._goal) {
        out << to_string(literal->second);
        out << *(literal->first) << endl;
    }
    out << "]" << endl;

    return out;
}
