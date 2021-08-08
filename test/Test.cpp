#include "IntArray.h"
#include "gtest/gtest.h"

struct IntArrayTest : testing::Test
{

};

TEST_F(IntArrayTest, test_normal_constructor)
{
    IntArray array{3};
    for(int idx = 0; idx < 3; ++idx)
    {
        array[idx] = idx;
    }

    ASSERT_EQ(0, array[0]);
    ASSERT_EQ(1, array[1]);
    ASSERT_EQ(2, array[2]);
}

TEST_F(IntArrayTest, test_function_size)
{
    IntArray array{3};
    for(int idx = 0; idx < 3; ++idx)
    {
        array[idx] = idx;
    }

    ASSERT_EQ(3, array.size());
}

