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

    TEST_F(ScoringTest, OneScoreLeft)
    {
	TapeDeque t;
	t.moveLeft(true);
	EXPECT_EQ(t.score(), 1);
    }

    TEST_F(ScoringTest, OneScoreRight)
    {
	TapeDeque t;
	t.moveRight(true);
	EXPECT_EQ(t.score(), 1);
    }

    TEST_F(ScoringTest, ScoreTapeBothDirections)
    {
	TapeDeque t;

	for(int i = 0; i < 5; i++)
	    t.moveLeft(false);

	for(int i = 0; i < 10; i++)
	    t.moveRight(true);

	EXPECT_EQ(t.score(), 10);
    }
}
