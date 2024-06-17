# tests/CMakeLists.txt

# Include the main source directory to access headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find the testing framework
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Find benchmarking framework
find_package(benchmark REQUIRED)

# Add the test executable
add_executable(color_class_tests color_class_tests.cpp)
target_link_libraries(color_class_tests ${GTEST_LIBRARIES} pthread)
add_test(NAME color_class_tests COMMAND color_class_tests)

# Add the test executable
add_executable(point_class_tests point_class_tests.cpp)
target_link_libraries(point_class_tests ${GTEST_LIBRARIES} pthread)
add_test(NAME point_class_tests COMMAND point_class_tests)

# Add benchmark executable
add_executable(benchmark_main ${CMAKE_SOURCE_DIR}/benchmark/benchmark_main.cpp)
target_link_libraries(benchmark_main benchmark::benchmark)
add_test(NAME run_benchmarks COMMAND benchmark_main)