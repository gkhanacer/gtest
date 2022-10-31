#include <iostream>
#include <gtest/gtest.h>
#include <vector>

#include "LibraryCode.hpp"

TEST(TestCountPossitive, BasicTest)
{
    // Arrange
    std::vector<int> inputVector{1, -2, 3, -4, 5, -6, -7};

    // Act
    int count = countPositives(inputVector);

    // Assert
    // Generally, first element is expected value, then actual value is second arg.
    ASSERT_EQ(3, count);
}

TEST(TestCountPossitive, EmptyVectorTest)
{
    // Arrange
    std::vector<int> inputVector{};

    // Act
    int count = countPositives(inputVector);

    // Assert
    // Generally, first element is expected value, then actual value is second arg.
    ASSERT_GE(0, count);
}

TEST(TestCountPossitive, AllNegativesTest)
{
    // Arrange
    std::vector<int> inputVector{-1, -2, -3, -4};

    // Act
    int count = countPositives(inputVector);

    // Assert
    // Generally, first element is expected value, then actual value is second arg.
    // ASSERT_EQ(20, count);
    EXPECT_EQ(20, count);
    std::cout << "After the assertion\n";
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}