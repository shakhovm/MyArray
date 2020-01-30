#include <gtest/gtest.h>
#include "MyArray.h"

#define SIZE 3
using namespace std;
class ArrayFixture : public :: testing::Test{
public:
    MyArray<int, SIZE> array1{0, 1, 2};
};


TEST_F(ArrayFixture, init) {


    EXPECT_EQ(array1.size(), SIZE);
    EXPECT_EQ(array1.max_size(), SIZE);
    EXPECT_EQ(array1[0], 0);
    EXPECT_EQ(array1[1], 1);
    EXPECT_EQ(array1[2], 2);
    array1[0] = 1;
    EXPECT_EQ(array1[0], 1);
    EXPECT_EQ(array1.front(), array1[0]);
    EXPECT_EQ(array1.back(), array1[2]);
}

TEST_F(ArrayFixture, iters) {

    EXPECT_EQ(*array1.begin(), 0);
    EXPECT_EQ(*(array1.end() - 1), 2);
    MyArray<int, 0> array2{};
    EXPECT_EQ(array2.begin(), array2.end());
    EXPECT_TRUE(array2.empty());
    EXPECT_EQ(array1.data(), array1.begin());
}

TEST_F(ArrayFixture, comparing) {
    MyArray<MyArray<int, SIZE>, SIZE - 1> newArray1{MyArray<int, SIZE>{1, 2, 3},
                                                    MyArray<int, SIZE>{3, 4, 5}};


    EXPECT_LE(newArray1.front(), newArray1.back());

    EXPECT_LT(newArray1.front(), newArray1.back());

    newArray1.front().swap(newArray1.back());

    EXPECT_GT(newArray1.front(), newArray1.back());
    EXPECT_GE(newArray1.front(), newArray1.back());

    MyArray<MyArray<int, SIZE>, SIZE - 1> newArray2{MyArray<int, SIZE>{3, 4, 5},
                                                    MyArray<int, SIZE>{1, 2, 3}};

    EXPECT_EQ(newArray1, newArray2);
    EXPECT_GE(newArray1, newArray2);
    EXPECT_LE(newArray1, newArray2);

    newArray2.front().fill(5);

    MyArray<int, SIZE> newArray3{5 ,5 ,5};
    EXPECT_EQ(newArray2.front(), newArray3);

    EXPECT_NE(newArray1, newArray2);

}



