#include "IntArray.h"
#include "gtest/gtest.h"

struct IntArrayTest : testing::Test
{
    void initArr(IntArray& array) const
    {
        for(int idx = 0; idx < array.size(); ++idx)
        {
            array[idx] = idx;
        }
    }

    void assertArr(const IntArray& array, const int num) const
    {
        ASSERT_EQ(num, array.size());
        for(int idx = 0; idx < array.size(); ++idx)
        {
            ASSERT_EQ(array[idx], idx);
        }
    }
};

TEST_F(IntArrayTest, test_constructor)
{
    IntArray array{3};
    initArr(array);
    assertArr(array, 3);
}

TEST_F(IntArrayTest, test_copy_constructor)
{
    IntArray array{3};
    initArr(array);
    assertArr(array, 3);

    IntArray arrayTmp{array};
    assertArr(arrayTmp, 3);
}

TEST_F(IntArrayTest, test_assignment_constructor)
{
    IntArray array{3};
    initArr(array);
    assertArr(array, 3);

    IntArray arrayTmp = array;
    assertArr(arrayTmp, 3);
}

TEST_F(IntArrayTest, test_function_size)
{
    IntArray array{3};
    initArr(array);
    ASSERT_EQ(3, array.size());
}

TEST_F(IntArrayTest, test_function_erase)
{
    IntArray array{3};
    ASSERT_EQ(3, array.size());

    array.erase();
    ASSERT_EQ(0, array.size());
}

TEST_F(IntArrayTest, test_function_overrided_operator)
{
    IntArray array{1};
    initArr(array);
    ASSERT_EQ(0, array[0]);
}

TEST_F(IntArrayTest, test_function_reallocate)
{
    IntArray array{3};
    ASSERT_EQ(3, array.size());

    array.reallocate(1);
    ASSERT_EQ(1, array.size());
}

TEST_F(IntArrayTest, test_function_resize)
{
    IntArray array{3};
    initArr(array);
    assertArr(array, 3);

    array.resize(2);
    ASSERT_EQ(2, array.size());
    ASSERT_EQ(0, array[0]);
    ASSERT_EQ(1, array[1]);
}

TEST_F(IntArrayTest, test_function_remove)
{
    IntArray array{3};
    initArr(array);
    assertArr(array, 3);

    array.remove(1);
    ASSERT_EQ(2, array.size());
    ASSERT_EQ(0, array[0]);
    ASSERT_EQ(2, array[1]);
}

TEST_F(IntArrayTest, test_function_insert)
{
    IntArray array{2};
    initArr(array);
    assertArr(array, 2);

    array.insertBefore(3, 1);
    ASSERT_EQ(3, array.size());
    ASSERT_EQ(0, array[0]);
    ASSERT_EQ(3, array[1]);
    ASSERT_EQ(1, array[2]);
}

TEST_F(IntArrayTest, test_function_insert_at_begining)
{
    IntArray array{1};
    initArr(array);
    assertArr(array, 1);

    array.insertAtBegining(3);
    ASSERT_EQ(2, array.size());
    ASSERT_EQ(3, array[0]);
    ASSERT_EQ(0, array[1]);
}

TEST_F(IntArrayTest, test_function_insert_at_end)
{
    IntArray array{1};
    initArr(array);
    assertArr(array, 1);

    array.insertAtEnd(3);
    ASSERT_EQ(2, array.size());
    ASSERT_EQ(0, array[0]);
    ASSERT_EQ(3, array[1]);
}

