#include "gtest/gtest.h"
#include "add.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(SuiteName, TestName1) {
    int expected = 3;
    int actual = add(1, 2);
    ASSERT_EQ(expected, actual);
}

TEST(SuiteName, TestName2) {
    int expected = 3;
    int actual = add(1, 3);
    ASSERT_EQ(expected, actual);
}
