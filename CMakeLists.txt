cmake_minimum_required(VERSION 3.10)
project(ray-tracing-engine)

# Set minimum C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source directory
add_subdirectory(src)

# Add testing directory
enable_testing()
add_subdirectory(tests)