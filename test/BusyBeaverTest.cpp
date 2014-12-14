#include "TapeDeque.hpp"
#include "BusyBeaver.hpp"

#include "gtest/gtest.h"

#include <cstddef>
#include <vector>
#include <tuple>

using std::cout;
using std::endl;
using std::vector;
using std::tuple;

namespace
{
    /*
     * Test cases provided by: http://en.wikipedia.org/wiki/Busy_beaver#Examples
     */
    class BusyBeaverTest : public ::testing::Test
    {
    protected:
    	BusyBeaverTest() {}
    	virtual ~BusyBeaverTest() {}
    	virtual void SetUp() {}
    	virtual void TearDown() {}
    };
    
    TEST_F(BusyBeaverTest, OneStateTwoSymbol)
    {
	vector< tuple<state_t*, state_t*>* > states;

	//diagram of this state table
	/*    A
	 * 0 1RH
	 * 1 n/a
	 */
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 1), new state_t(true, true, 1)));
	
	BusyBeaver b(states);
	b.run();

	EXPECT_EQ(b.getScore(), 1);
	EXPECT_EQ(b.getIterations(), 1);
    }

    TEST_F(BusyBeaverTest, TwoStateTwoSymbol)
    {
	vector< tuple<state_t*, state_t*>* > states;

	//diagram of this state table
	/*    A    B
	 * 0 1RB  1LA
	 * 1 1LB  1RH
	 */
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 1), new state_t(true, false, 1)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, false, 0), new state_t(true, false, 2)));
	
	BusyBeaver b(states);
	b.run();

	EXPECT_EQ(b.getScore(), 4);
	EXPECT_EQ(b.getIterations(), 6);
    }

    TEST_F(BusyBeaverTest, ThreeStateTwoSymbol)
    {
	vector< tuple<state_t*, state_t*>* > states;

	//diagram of this state table
	/*    A    B    C
	 * 0 1RB  0RC  1LC
	 * 1 1RH  1RB  1LA
	 */
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 1), new state_t(true, true, 3)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(false, true, 2), new state_t(true, false, 0)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, false, 2), new state_t(true, false, 0)));
	
	BusyBeaver b(states);
	b.run();

	EXPECT_EQ(b.getScore(), 6);
	EXPECT_EQ(b.getIterations(), 14);
    }

    TEST_F(BusyBeaverTest, FourStateTwoSymbol)
    {
	vector< tuple<state_t*, state_t*>* > states;

	//diagram of this state table
	/*    A    B    C    D
	 * 0 1RB  1LA  1RH  1RD
	 * 1 1LB  0LC  1LD  0RA
	 */
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 1), new state_t(true, false, 1)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, false, 0), new state_t(false, false, 2)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 4), new state_t(true, false, 3)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 3), new state_t(false, true, 0)));
	
	BusyBeaver b(states);
	b.run();

	EXPECT_EQ(b.getScore(), 13);
	EXPECT_EQ(b.getIterations(), 107);
    }

    TEST_F(BusyBeaverTest, FiveStateTwoSymbol)
    {
	vector< tuple<state_t*, state_t*>* > states;

	//diagram of this state table
	/*    A    B    C    D    E
	 * 0 1RB  1RC  1RD  1LA  1RH
	 * 1 1LC  1RB  0LE  1LD  0LA
	 */
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 1), new state_t(true, false, 2)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 2), new state_t(true, true, 1)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 3), new state_t(false, false, 4)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, false, 0), new state_t(true, false, 3)));
	states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 5), new state_t(false, false, 0)));
	
	BusyBeaver b(states);
	b.run();

	EXPECT_EQ(b.getScore(), 4098);
	EXPECT_EQ(b.getIterations(), 47176870);
    }
}
