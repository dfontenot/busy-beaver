#include "tape_deque.hpp"

#include "gtest/gtest.h"

#include <cstddef>

namespace
{
    class MovementTest : public ::testing::Test
    {	
    protected:
    	MovementTest() {}
    	virtual ~MovementTest() {}
    	virtual void SetUp() {}
    	virtual void TearDown() {}
    };
    
    TEST_F(MovementTest, MoveRight)
    {
    	TapeDeque t;
    	t.moveRight(true);
    	node_t* hd = t.h();
    	node_t* cur = t.getPosition();

    	EXPECT_NE(hd, cur);
    	EXPECT_EQ(hd->right, cur);
    	EXPECT_EQ(cur->value, true);
    }
}
