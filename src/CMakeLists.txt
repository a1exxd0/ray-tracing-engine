# src/CMakeLists.txt

# Add include
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add executable
add_executable(main print_images.cpp)