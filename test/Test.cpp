#include "Array.h"
#include "gtest/gtest.h"

struct ArrayTest : testing::Test
{
    void initIntArr(Array<int>& array) const
    {
        for(int idx = 0; idx < array.size(); ++idx)
        {
            array[idx] = idx;
        }
    }

    void assertIntArr(const Array<int>& array, const int num) const
    {
        ASSERT_EQ(num, array.size());
        for(int idx = 0; idx < array.size(); ++idx)
        {
            ASSERT_EQ(array[idx], idx);
        }
    }

    void initDoubleArr(Array<double>& array) const
    {
        for(int idx = 0; idx < array.size(); ++idx)
        {
            array[idx] = idx + 0.1;
        }
    }

    void assertDoubleArr(const Array<double>& array, const int num) const
    {
        ASSERT_EQ(num, array.size());
    }
};

TEST_F(ArrayTest, test_constructor)
{
    Array<int> array{3};
    initIntArr(array);
    assertIntArr(array, 3);
}

TEST_F(ArrayTest, test_copy_constructor)
{
    Array<int> array{3};
    initIntArr(array);
    assertIntArr(array, 3);

    Array<int> arrayTmp{array};
    assertIntArr(arrayTmp, 3);
}

TEST_F(ArrayTest, test_assignment_constructor)
{
    Array<int> array{3};
    initIntArr(array);
    assertIntArr(array, 3);

    Array<int> arrayTmp = array;
    assertIntArr(arrayTmp, 3);
}

TEST_F(ArrayTest, test_function_size)
{
    Array<int> array{3};
    initIntArr(array);
    ASSERT_EQ(3, array.size());
}

TEST_F(ArrayTest, test_function_erase)
{
    Array<int> array{3};
    ASSERT_EQ(3, array.size());

    array.erase();
    ASSERT_EQ(0, array.size());
}

TEST_F(ArrayTest, test_function_overrided_operator)
{
    Array<int> array{1};
    initIntArr(array);
    ASSERT_EQ(0, array[0]);
}

TEST_F(ArrayTest, test_function_reallocate)
{
    Array<int> array{3};
    ASSERT_EQ(3, array.size());

    array.reallocate(1);
    ASSERT_EQ(1, array.size());
}

TEST_F(ArrayTest, test_function_resize)
{
    Array<int> array{3};
    initIntArr(array);
    assertIntArr(array, 3);

    array.resize(2);
    ASSERT_EQ(2, array.size());
    ASSERT_EQ(0, array[0]);
    ASSERT_EQ(1, array[1]);
}

TEST_F(ArrayTest, test_function_remove)
{
    Array<int> array{3};
    initIntArr(array);
    assertIntArr(array, 3);

    array.remove(1);
    ASSERT_EQ(2, array.size());
    ASSERT_EQ(0, array[0]);
    ASSERT_EQ(2, array[1]);
}

TEST_F(ArrayTest, test_function_insert)
{
    Array<int> array{2};
    initIntArr(array);
    assertIntArr(array, 2);

    array.insertBefore(3, 1);
    ASSERT_EQ(3, array.size());
    ASSERT_EQ(0, array[0]);
    ASSERT_EQ(3, array[1]);
    ASSERT_EQ(1, array[2]);
}

TEST_F(ArrayTest, test_function_insert_at_begining)
{
    Array<int> array{1};
    initIntArr(array);
    assertIntArr(array, 1);

    array.insertAtBegining(3);
    ASSERT_EQ(2, array.size());
    ASSERT_EQ(3, array[0]);
    ASSERT_EQ(0, array[1]);
}

TEST_F(ArrayTest, test_function_insert_at_end)
{
    Array<int> array{1};
    initIntArr(array);
    assertIntArr(array, 1);

    array.insertAtEnd(3);
    ASSERT_EQ(2, array.size());
    ASSERT_EQ(0, array[0]);
    ASSERT_EQ(3, array[1]);
}

TEST_F(ArrayTest, test_double_array_size)
{
    Array<double> array{3};
    initDoubleArr(array);
    assertDoubleArr(array, 3);
}

TEST_F(ArrayTest, test_double_array_operator)
{
    Array<double> array{2};
    initDoubleArr(array);
    ASSERT_TRUE(array[0] - 0.1 < 1e-3);
    ASSERT_TRUE(array[1] - 1.1 < 1e-3);
}

