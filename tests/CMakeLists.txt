# tests/CMakeLists.txt

# Include the main source directory to access headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find the testing framework
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(color_class_tests color_class_tests.cpp)
target_link_libraries(color_class_tests ${GTEST_LIBRARIES} pthread)
add_test(NAME color_class_tests COMMAND color_class_tests)

# Add the test executable
add_executable(point_class_tests point_class_tests.cpp)
target_link_libraries(point_class_tests ${GTEST_LIBRARIES} pthread)
add_test(NAME point_class_tests COMMAND point_class_tests)
