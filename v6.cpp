#include <iostream>
#include <chrono>
#include "shared.hpp"

using namespace std;
using namespace std::chrono;

// trapezoidal rule of integration with fixed time step
template <typename T>
double integrate(T generator) {
    double acc = 0;
    double t;
    while (generator(t)) {
        acc += dt_fixed * f(t);
    }
    acc -= 0.5 * dt_fixed * f(0);
    acc -= 0.5 * dt_fixed * f(tau);
    return acc;
}

int main() {
    steady_clock::time_point t1 = steady_clock::now();

    long long int i = 0;
    auto g = [=, &i](double& t) {
        t = dt_fixed * static_cast<double>(i);
        ++i;
        return i < n_fixed;
    }; 
    double res = integrate(g);

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "\x1b[32mv6\x1b[0m\n"
         << "number of timesteps: " << n_fixed           << '\n'
         << "result = "             << res               << '\n'
         << "computation takes "    << time_span.count() << " seconds\n";

    return 0;
}
