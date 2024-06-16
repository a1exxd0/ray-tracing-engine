// tests/test_mylib.cpp
#include <gtest/gtest.h>
#include "point3.h"

TEST(Example_Test, Add_Colors) {
    // Arrange
    rte::point3 expected(20.0, 50.0, 100.0);
    // Act
    rte::point3 prev(10.0 , 25.0 , 50.0);
    rte::point3 result = prev + prev;


    // Assert
    EXPECT_EQ(result, expected);
}

TEST(Example_Test, Multiply_Colors) {
    // Arrange
    rte::point3 expected(20.0, 50.0, 100.0);
    // Act
    rte::point3 prev(10.0 , 25.0 , 50.0);
    rte::point3 multiply(2.0, 2.0, 2.0);
    rte::point3 result = prev * multiply;


    // Assert
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}