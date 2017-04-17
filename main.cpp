#include <iostream>
#include <memory>
#include <string>
#include "state_machine.h"

using namespace std;

class StatefulObject: public StateMachine
{
public:
    StatefulObject()
    {
        AddTransition(start, make_pair(idle, running), []{return true;});
        AddTransition(stop, make_pair(running, idle), []{return true;});
        AddTransition(cancel, make_pair(idle, cancelled), []{return true;});
        AddTransition(reset, make_pair(cancelled, idle));

        Init(idle);
        cout << GetState() << endl;

        DoTransition(start);
        cout << GetState() << endl;

        DoTransition(stop);
        cout << GetState() << endl;

        DoTransition(cancel);
        cout << GetState() << endl;

        DoTransition(reset);
        cout << GetState() << endl;
    }
};


int main(int argc, char* argv[])
{
    StatefulObject rs;
	return 0;
}
