#include <gtest/gtest.h>
#include "state_machine.h"

class StateMachineTest: public ::testing::Test {
 protected:

	StateMachineTest() {
		_sm.AddTransition(start, std::make_pair(idle, running));
		_sm.AddTransition(stop, std::make_pair(running, cancelled));
		_sm.Init(idle);
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

TEST_F(StateMachineTest, InitialStateShouldBeIdle)
{
	auto state = _sm.GetState();
	EXPECT_EQ(state, idle);
}

TEST_F(StateMachineTest, TransitionIdleToStart)
{
	auto res = _sm.Transition(start);
	EXPECT_TRUE(res);
	auto state = _sm.GetState();
	EXPECT_EQ(state, running);
}


TEST_F(StateMachineTest, TransitionStartToCancelled)
{
	_sm.Transition(start);
	auto res = _sm.Transition(stop);
	ASSERT_TRUE(res);
	auto state = _sm.GetState();
	EXPECT_EQ(cancelled, state);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
