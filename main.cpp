#include <iostream>
#include <memory>
#include <string>
#include "state_machine.h"

using namespace std;



int main(int argc, char* argv[])
{
	StateMachine sm;
	sm.init(initialized);
	auto trans = std::make_pair(idle, running);
	//sm.AddTransition(start, trans, std::function<bool()>([]() {return true;}));
	sm.AddTransition(start, std::make_pair(initialized, running), 
			std::function<bool()>([]() {return true;}));
	//sm.AddTransition(start, cancelled, running);
	//sm.AddTransition(reset, cancelled, initialized);
	sm.PrintTransitions();
	auto current = sm.GetState();
	cout << "Current: " << current << endl;
	sm.Transition(start);
	current = sm.GetState();
	cout << "Current: " << current << endl;
	return 0;
}
