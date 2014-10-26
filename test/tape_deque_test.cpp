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
    
    TEST(ConstructorTest, Init)
    {
	TapeDeque t;
	EXPECT_EQ(t.h(), t.getPosition());
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
