cmake_minimum_required(VERSION 3.0)

# project information
project(semiprof)
enable_language(CXX)

# turn on profiler
add_definitions(-DSEMIPROF)

# create the semiprof library
add_library(semiprof src/profiler.cpp)
target_include_directories(semiprof PUBLIC ${PROJECT_SOURCE_DIR}/include/semiprof)

# compile the examples
add_subdirectory(examples)
