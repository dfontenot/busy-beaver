#include "tape_deque.hpp"

#include "gtest/gtest.h"

#include <cstddef>

namespace
{
    class ConstructorTest : public ::testing::Test
    {	
    protected:
	ConstructorTest() {}
	virtual ~ConstructorTest() {}
	virtual void SetUp() {}
	virtual void TearDown() {}
    };

    TEST_F(ConstructorTest, Init)
    {
	TapeDeque t;
	node_t* hd = t.h();
	EXPECT_EQ(hd, t.getPosition());
	EXPECT_EQ(hd->value, false);
	EXPECT_EQ(hd->left, (node_t*)NULL);
	EXPECT_EQ(hd->right, (node_t*)NULL);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
