#pragma once

#include <functional>
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
        std::size_t operator()(const Action a) const
        {
            return static_cast<std::size_t>(a);
        }
    };

    template<>
    struct hash<State>
    {
        std::size_t operator()(const State s) const
        {
            return static_cast<std::size_t>(s);
        }
    };
}

using Transition = std::pair<State, State>;

// State: Current State
// Actions: Allowed Actions
using ActionMap = std::unordered_map<State, std::vector<Action>>;

// Action: Desired action
// Result: State resulting from action
using ResultMap = std::unordered_map<Action, State>;

// Action: Desired Action
// Function: State transition success depends on result 
using FunctionMap = std::unordered_map<Action, std::function<bool()>>;

class StateMachine
{
public:
    State GetState() { return _current; }

protected:
    StateMachine();
    virtual ~StateMachine();
    bool Init(State initial_state);
    void AddTransition(Action action, Transition transition, const std::function<bool()> &func = std::function<bool()>(nullptr));
    bool DoTransition(Action action);
    void PrintTransitions();

private:
    ActionMap _actionMap;
    ResultMap _resultMap;
    FunctionMap _funcMap;
    State _current;
};
