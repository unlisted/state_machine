#include <iostream>
#include "state_machine.h"

StateMachine::StateMachine()
{
	_actionMap.clear();
}

void StateMachine::AddTransition(Action action, Transition transition, std::function<bool()> func)
{
	auto& actions = _actionMap[transition.first];

	actions.push_back(action);
	_resultMap[action] = transition.second;
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
	auto found = _resultMap.find(action);
    auto valid = false;
	if (found != _resultMap.end()) {
		auto& actions = _actionMap[_current];
		for (auto& it : actions) {
			if (it == action) {
                valid = true;
				break;
			}
		}
	}

    if (!valid)
        return false;

    if (_funcMap[action] == nullptr || _funcMap[action]()) {
        _current = _resultMap[action];
        return true;
    }

	return false;

}

StateMachine::~StateMachine()
{
}
