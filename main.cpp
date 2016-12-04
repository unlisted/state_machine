#include <iostream>
#include "state_machine.h"

using namespace std;



int main(int argc, char* argv[])
{
	cout << "hello world." << endl;
	StateMachine sm;
	auto trans = std::make_pair(idle, running);
	sm.AddTransition(start, trans);
	cout << std::endl;
	//sm.AddTransition(stop, running, cancelled);
	//sm.AddTransition(start, cancelled, running);
	//sm.AddTransition(reset, cancelled, initialized);
	sm.PrintTransitions();
	return 0;
}
