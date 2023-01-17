#include "action.hh"

using namespace std;

std::string to_string(LiteralState s) {
	switch (s) {
		case LiteralState::NEGATIVE:
			return "NOT ";
			break;
		case LiteralState::UNKNOWN:
			return "UNKNOWN ";
			break;
		case LiteralState::KNOWN:
			return "KNOWN ";
			break;
		default:
			break;
	}
	return "";
}

Action::Action(const string& name, const ParameterList* params,
               const PreconditionList* precond, const EffectList* effects)
    : _name(name),
      _params(params->first),
      _types(params->second),
      _precond(precond),
      _effects(effects) {
    for (auto& para : *_params) {
        if (para[0] == '?') {
            auto temp = _types->at(para);
            _types->erase(para);
            para = para.substr(1);
            _types->emplace(para, temp);
        }
    }
}

Action::~Action() {
    if (_params) delete _params;
    if (_types) delete _types;

    for (auto precondition : *_precond) {
        delete precondition;
    }
    if (_precond) delete _precond;

    for (auto effect : *_effects) {
        delete effect;
    }
    delete _effects;
}

ostream& operator<<(ostream& out, const Action& action) {
    out << "Action(name:" << action._name << ")" << endl;
    if (action._params) {
        out << ">> params:[";
        auto size = action._params->size();
        for (decltype(size) i = 0; i < size; ++i) {
            auto parameter = (*action._params)[i];
            if (i == 0) {
                out << parameter;
            } else {
                out << ", " << parameter;
            }
            if (action._types &&
                action._types->find(parameter) != action._types->end()) {
                out << " - " << action._types->at(parameter);
            }
        }
        out << "]" << endl;
    }
    out << ">> precond:[";
    auto size = action._precond->size();
    for (decltype(size) i = 0; i < size; ++i) {
        auto literal = (*action._precond)[i];
        auto predicate = literal->first;
        auto state = literal->second;
        if (i == 0) {
            out << to_string(state);
            out << *predicate;
        } else {
            out << ", ";
            out << to_string(state);
            out << *predicate;
        }
    }
    out << "]" << endl;
    size = action._effects->size();
    out << ">> effects:[";
    for (decltype(size) i = 0; i < size; ++i) {
        auto literal = (*action._effects)[i];
        auto predicate = literal->first;
        auto state = literal->second;
        if (i == 0) {
            out << to_string(state);
            out << *predicate;
        } else {
            out << ", ";
            out << to_string(state);
            out << *predicate;
        }
    }
    out << "])" << endl;
    return out;
}
