#include <iostream>
#include <chrono>
#include <vector>
#include "shared.hpp"

using namespace std;
using namespace std::chrono;

// number of intervals for numerical integration
long long n = llround(tau / dT);
double dt = tau / static_cast<double>(n - 1);

double integrate(vector<double> t_nodes) {
    // trapezoidal rule of integration with fixed time step
    double acc = 0;
    for(auto t: t_nodes) {
        acc += dt * f(t);
    }
    acc -= 0.5 * dt * f(tau);
    return acc;
}

int main() {
    steady_clock::time_point t1 = steady_clock::now();

    vector<double> t_nodes;
    for (size_t i = 0; i < static_cast<size_t>(n); ++i) {
        t_nodes.push_back(dt * static_cast<double>(i));
    }
    double res = integrate(t_nodes);

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "\x1b[32mv2\x1b[0m\n"
         << "number of timesteps: " << n   << '\n'
         << "result = "             << res << '\n'
         << "computation takes "    << time_span.count() << " seconds\n";

    return 0;
}
