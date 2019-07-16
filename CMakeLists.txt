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
  include(CMakePackageConfigHelpers)
  include(GNUInstallDirs)

  install(TARGETS semiprof
          EXPORT semiprof_targets 
          LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
          INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

  install(EXPORT semiprof_targets
          FILE semiprofConfig.cmake
          NAMESPACE semiprof::
          DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/semiprof")

  install(FILES "${semiprof_SOURCE_DIR}/include/semiprof/semiprof.hpp"
          DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

  write_basic_package_version_file(
    "${semiprof_BINARY_DIR}/semiprofConfigVersion.cmake"
    VERSION ${semiprof_VERSION}
    COMPATIBILITY SameMajorVersion)

  install(FILES "${semiprof_BINARY_DIR}/semiprofConfigVersion.cmake"
          DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/semiprof")
endif()
