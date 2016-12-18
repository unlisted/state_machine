#include <iostream>
#include <memory>
#include <string>
#include "state_machine.h"

using namespace std;



int main(int argc, char* argv[])
{
	StateMachine sm;
	auto trans = std::make_pair(idle, running);
	sm.AddTransition(start, trans, std::make_unique<std::function<bool()>>(nullptr));
	//sm.AddTransition(start, cancelled, running);
	//sm.AddTransition(reset, cancelled, initialized);
	sm.PrintTransitions();
	return 0;
}
