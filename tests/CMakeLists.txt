# tests/CMakeLists.txt

# Include the main source directory to access headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find the testing framework
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(run_tests run_tests.cpp)

# Link the test executable with GTest and pthread
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)

# Add the test to CTest
add_test(NAME a_test COMMAND run_tests)
