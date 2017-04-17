#include <iostream>
#include "state_machine.h"

StateMachine::StateMachine()
{
	_actionMap.clear();
}

void StateMachine::AddTransition(Action action, Transition transition, const std::function<bool()> &func)
{
    // get ref to actions allow from initial state.
    // accessor creates if not exist.
	auto& actions = _actionMap[transition.first];

    // add action to list
	actions.push_back(action);

    // set result
	_resultMap[action] = transition.second;

    // set transition function
    _funcMap[action] = func;

}

bool StateMachine::Init(State initial_state)
{
	if (_actionMap.size() == 0)
		return false;

	_current = initial_state;
    return true;
}

void StateMachine::PrintTransitions()
{
	for (auto& it : _actionMap) {
		std::cout << "from state: ";
		std::cout << it.first << std::endl;
	
		for (auto& itt : it.second)
			std::cout << "valid action: " << itt << " " << std::endl;
	}

	for (auto& it : _resultMap) {
		std::cout << "from state " << it.first << " to state " << it.second << std::endl;
	}
}

bool StateMachine::DoTransition(Action action)
{
    // check if desired state exists
	auto found = _resultMap.find(action);
    if (found == _resultMap.end())
        return false;

    // check if transition is valid
    auto valid = false;
    auto& actions = _actionMap[_current];
    for (auto& it : actions) {
        if (it == action) {
            valid = true;
            break;
        }
    }

    if (!valid)
        return false;

    // check result of function if one exists
    if (_funcMap[action] == nullptr || _funcMap[action]()) {
        _current = _resultMap[action];
        return true;
    }

	return false;

}

StateMachine::~StateMachine()
{
}
