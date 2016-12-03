#include <iostream>
#include "state_machine.h"

StateMachine::StateMachine()
{
	_actionMap.clear();
}


bool StateMachine::AddTransition(Action action, State from, State to)
{
	auto& actions = _actionMap[from];
	std::cout << "size of action list: " << actions.size() << std::endl;

	actions.push_back(action);
	_resultMap[action] = to;
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

	auto found = _resultMap.find(action);
	if (found != _resultMap.end()) {
		auto& actions = _actionMap[_current];
		for (auto& it : actions) {
			if (it == action) {
				return true;
			}
		}
	}

	return false;
}

StateMachine::~StateMachine()
{
}