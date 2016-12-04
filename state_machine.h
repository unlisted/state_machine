#pragma once

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

using ActionMap = std::unordered_map<State, std::vector<Action>>;
using ResultMap = std::unordered_map<Action, State>;
using Transition = std::tuple<State, State>;

class StateMachine
{
public:
	StateMachine();
	virtual ~StateMachine();
	bool AddTransition(Action action, std::pair<State, State> transition);
	bool Transition(Action action);
	void PrintTransitions();
private:
	ActionMap _actionMap;
	ResultMap _resultMap;
	State _current;
};
