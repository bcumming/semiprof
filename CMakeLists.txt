cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

if(NOT DEFINED PROJECT_NAME)
  set(SEMIPROF_NOT_SUBPROJECT ON)
endif()

project(semiprof VERSION 1.0 LANGUAGES CXX)

add_library(semiprof STATIC "${semiprof_SOURCE_DIR}/src/profiler.cpp")
target_include_directories(semiprof PUBLIC 
  $<BUILD_INTERFACE:${semiprof_SOURCE_DIR}/include/semiprof>
  )
target_compile_definitions(semiprof PRIVATE SEMIPROF) # Turn on profiler

if(SEMIPROF_NOT_SUBPROJECT)
  add_subdirectory(examples)
endif()

if(SEMIPROF_NOT_SUBPROJECT)
  install(TARGETS semiprof
          EXPORT semiprof_targets 
          LIBRARY DESTINATION lib
          INCLUDES DESTINATION include)

  install(EXPORT semiprof_targets
          FILE semiprofConfig.cmake
          NAMESPACE semiprof::
          DESTINATION lib/cmake/semiprof)

  install(FILES "${semiprof_SOURCE_DIR}/include/semiprof/semiprof.hpp"
          DESTINATION include)

  include(CMakePackageConfigHelpers)
  write_basic_package_version_file(
    "${semiprof_BINARY_DIR}/semiprofConfigVersion.cmake"
    VERSION ${semiprof_VERSION}
    COMPATIBILITY SameMajorVersion)

  install(FILES "${semiprof_BINARY_DIR}/semiprofConfigVersion.cmake"
          DESTINATION lib/cmake/semiprof)
endif()
