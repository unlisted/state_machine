#include <iostream>
#include "state_machine.h"

StateMachine::StateMachine()
{
	_actionMap.clear();
}

bool StateMachine::AddTransition(Action action, std::pair<State, State> transition, std::function<bool()> function)
{
	auto& actions = _actionMap[transition.first];

	actions.push_back(action);
	_resultMap[action] = transition.second;
	_functionMap[action] = function;
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

bool StateMachine::Transition(Action action)
{

	auto valid = false;
	auto result = _resultMap.find(action);

	if (result != _resultMap.end()) {
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

	if (_functionMap[action]()) {
		_current = result->second;
		return true;
	}

	return false;

}

StateMachine::~StateMachine()
{
}
