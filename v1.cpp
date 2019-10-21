#include <iostream>
#include <chrono>
#include <cmath>
#include "shared.hpp"

using namespace std;
using namespace std::chrono;

// number of intervals for numerical integration
long long n = llround(tau / dT);

double integrate() {
    // trapezoidal rule of integration with fixed time step
    double dt = tau / static_cast<double>(n - 1);
    double acc = 0;
    for(long long i = 1; i < n - 1; ++i) {
        double t = dt * static_cast<double>(i);
        acc += dt * f(t);
    }
    acc += 0.5 * dt * f(tau);
    return acc;
}

int main() {
    steady_clock::time_point t1 = steady_clock::now();
    double res = integrate();
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "\x1b[32mv1\x1b[0m\n"
         << "number of timesteps: " << n   << '\n'
         << "result = "             << res << '\n'
         << "computation takes "    << time_span.count() << " seconds\n";
    return 0;
}
