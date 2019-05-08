find_package(OpenMP REQUIRED)
if (OpenMP_CXX_FOUND)
    set(OPENMP_DEPS OpenMP::OpenMP_CXX)
    add_executable(omp omp.cpp)
    target_link_libraries(omp LINK_PUBLIC ${OPENMP_DEPS} semiprof)
endif()

