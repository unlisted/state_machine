#include <iostream>
#include <memory>
#include <string>
#include "state_machine.h"

using namespace std;



int main(int argc, char* argv[])
{
	StateMachine sm;
    std::function<bool()> transFunc([]{ return true; });
	auto trans = std::make_pair(idle, running);
	sm.AddTransition(start, trans, transFunc );
	cout << std::endl;
	sm.AddTransition(reset, std::make_pair(cancelled, initialized), transFunc);
	sm.PrintTransitions();
	auto current = sm.GetState();
	cout << "Current: " << current << endl;
	sm.Transition(start);
	current = sm.GetState();
	cout << "Current: " << current << endl;
	return 0;
}
