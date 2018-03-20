#include <iostream>
#include <vector>

#include <omp.h>

#include <semiprof/semiprof.hpp>

int main() {
    std::cout << "-----------------------\n"
              << "OpenMP semiprof example\n"
              << "-----------------------\n\n"
              << "Using " << omp_get_max_threads() << " threads\n";


    const size_t n = 1<<26;

    std::vector<int> a(n, 1);
    std::vector<int> b(n, 2);
    std::vector<int> c(n, 3);

    size_t i = 0;

    PE(add);
    for (i=0u; i<n; ++i) {
        c[i] += a[i] + b[i];
    }
    PL();

    std::cout << semiprof::profiler_summary() << "\n";

    std::cout << c.back() << "\n";

    return 0;
}
