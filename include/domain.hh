#ifndef _DOMAIN_HH_
#define _DOMAIN_HH_

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <unordered_set>

#include "action.hh"

class Domain {
public:
	explicit Domain(const std::string &name);
	virtual ~Domain();

	void set_requirements(std::vector<std::string>* requirements);
	void set_predicates(std::vector<Predicate*>* predicates);
	void set_actions(std::vector<Action*>* actions);
	void set_types(std::unordered_set<std::string>* types);

	friend std::ostream &operator<<(std::ostream &os, const Domain &domain);

	std::string               _name;
	std::vector<std::string> *_requirements;
	std::unordered_set<std::string> *_types;
	std::vector<Predicate*>  *_predicates;
	std::vector<Action*>     *_actions;
};

#endif // _DOMAIN_HH_
