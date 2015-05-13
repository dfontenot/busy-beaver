#include "TapeDeque.hpp"

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
	EXPECT_EQ(hd->left, (node_t*)NULL);
    	EXPECT_EQ(hd->value, true);
	EXPECT_EQ(cur->value, false);
    }

    TEST_F(MovementTest, MoveLeft)
    {
	TapeDeque t;
    	t.moveLeft(true);
    	node_t* hd = t.h();
    	node_t* cur = t.getPosition();

    	EXPECT_NE(hd, cur);
    	EXPECT_EQ(hd->left, cur);
	EXPECT_EQ(hd->right, (node_t*)NULL);
	EXPECT_EQ(hd->value, true);
    	EXPECT_EQ(cur->value, false);
    }

    TEST_F(MovementTest, BackAndForthLeft)
    {
	int i;
	TapeDeque t;

	// go left 5 cells
	for(i = 0; i < 5; i++)
	    t.moveLeft(true);

	// verify
	node_t* cur = t.h();
	for(i = 0; i < 5; i++)
	{
	    EXPECT_EQ(cur->value, true);
	    EXPECT_EQ(cur->left->right, cur);
	    cur = cur->left;
	}
	EXPECT_EQ(cur, t.getPosition());

	// go right 5 cells
	cur = t.getPosition();
	for(i = 0; i < 5; i++)
	{
	    t.moveRight(false);
	    cur = cur->right;
	    EXPECT_EQ(cur->value, true); // hasn't been overwritten yet
	}
    }

    TEST_F(MovementTest, BackAndForthRight)
    {
	int i;
	TapeDeque t;

	// go right 5 cells
	for(i = 0; i < 5; i++)
	    t.moveRight(false);

	// verify
	node_t* cur = t.h();
	for(i = 0; i < 5; i++)
	{
	    EXPECT_EQ(cur->value, false);
	    EXPECT_EQ(cur->right->left, cur);
	    cur = cur->right;
	}
	EXPECT_EQ(cur, t.getPosition());

	// go left 5 cells
	cur = t.getPosition();
	for(i = 0; i < 5; i++)
	{
	    t.moveLeft(true);
	    cur = cur->left;
	    EXPECT_EQ(cur->value, false);
	}
    }
}
