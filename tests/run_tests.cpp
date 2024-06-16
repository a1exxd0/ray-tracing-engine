// tests/test_mylib.cpp
#include <gtest/gtest.h>

TEST(Example_Test, Test1) {
    // Arrange
    int expected = 42;
    // Act
    int result = 42;
    // Assert
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
