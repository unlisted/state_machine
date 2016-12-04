#include <gtest/gtest.h>
#include "state_machine.h"

class StateMachineTest: public ::testing::Test {
 protected:

	StateMachineTest() {
	}

    virtual ~StateMachineTest() {
		// You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
    }

    virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
    }

    // Objects declared here can be used by all tests in the test case for StateMachine.
	//
	StateMachine _sm;
};

// tests that AddTransition increase size of maps
TEST_F(StateMachineTest, AddTransitionIncreaseMapsSize)
{
	EXPECT_EQ(0, _sm.Size());
	_sm.AddTransition(start, std::make_pair(idle, running));
	EXPECT_EQ(1, _sm.Size());
}

TEST_F(StateMachineTest, TransitionStart)
{
	_sm.AddTransition(start, std::make_pair(idle, running));
	_sm.Transition(start);
	_sm.GetState();

}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
