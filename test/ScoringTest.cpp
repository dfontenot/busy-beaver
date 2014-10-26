#include "TapeDeque.hpp"

#include "gtest/gtest.h"

#include <cstddef>

namespace
{
    class ScoringTest : public ::testing::Test
    {
    protected:
    	ScoringTest() {}
    	virtual ~ScoringTest() {}
    	virtual void SetUp() {}
    	virtual void TearDown() {}
    };

    TEST_F(ScoringTest, EmptyTapeDequeScore)
    {
	TapeDeque t;
	EXPECT_EQ(t.score(), 0);
    }

    TEST_F(ScoringTest, ScoreTapeBothDirections)
    {
	TapeDeque t;

	for(int i = 0; i < 5; i++)
	    t.moveLeft(false);

	for(int i = 0; i < 10; i++)
	    t.moveRight(true);

	// score of 9 expected as the first node was not part of the
	// 5 nodes created when the tape deque moved left
	EXPECT_EQ(t.score(), 9);
    }
}
