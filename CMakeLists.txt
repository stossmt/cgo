cmake_minimum_required(VERSION 3.20)

project(cgo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Allows absolute include paths
include_directories(${CMAKE_SOURCE_DIR})

# Allows building test executables in this CMake file
enable_testing()
include(GoogleTest)

# Require external dependencies
find_package(fmt CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

# Add subdirectories
add_subdirectory(compiler)
add_subdirectory(tool)

# Build main executable
add_executable(cgo cmd/cgo.cc)
target_link_libraries(cgo 
    compiler 
    tool
    fmt::fmt
)

# Build test executable
add_executable(cgo_tests ${GLOBAL_TEST_SOURCES})
target_link_libraries(
    cgo_tests 
    GTest::gtest_main 
)
gtest_discover_tests(cgo_tests)
