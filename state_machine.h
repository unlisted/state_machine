#pragma once

#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

enum State {
	initialized,
	idle,
	running,
	finished,
	cancelled,
	error
};

enum Action {
	start,
	stop,
	cancel,
	reset,
	finish
};

namespace std {

	template<>
	struct hash<Action> {
		std::size_t operator()(const Action& a) const
		{
			return std::hash<int>()(a);
		}
	};

	template<>
	struct hash<State>
	{
		std::size_t operator()(const State& s) const
		{
			return std::hash<int>()(s);
		}
	};
}

// State: Current State
// Actions: Allowed Actions
using ActionMap = std::unordered_map<State, std::vector<Action>>;

// Action: Desired action
// Result: State resulting from action
using ResultMap = std::unordered_map<Action, State>;

// Action: Desired Action
// Function: State transition success depends on result 
using FunctionMap = std::unordered_map<Action, std::function<bool()>>;
using Transition = std::tuple<State, State>;

class StateMachine
{
public:
	StateMachine();
	virtual ~StateMachine();
	void init(State state) {_current = state;}
	bool AddTransition(Action action, std::pair<State, State> transition,
			std::function<bool()> func);
	bool Transition(Action action);
	bool Init(State initial_state);

	void PrintTransitions();
	size_t Size() { return _actionMap.size(); }
	State GetState() { return _current; }
private:
	ActionMap _actionMap;
	FunctionMap _functionMap;
	ResultMap _resultMap;
	State _current;
};
