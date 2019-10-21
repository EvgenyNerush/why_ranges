#include <iostream>
#include <chrono>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/transform.hpp>

#include "shared.hpp"

using namespace std;
using namespace std::chrono;

// number of intervals for numerical integration
long long n = llround(tau / dT);
double dt = tau / static_cast<double>(n - 1);

template <typename T>
double integrate(T t_nodes) {
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

    auto t_nodes = ranges::v3::iota_view(0, n)
                 | ranges::v3::views::transform(
                         [](long long i){ return dt * static_cast<double>(i); }
                   );
    double res = integrate(t_nodes);

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "\x1b[32mv4\x1b[0m\n"
         << "number of timesteps: " << n   << '\n'
         << "result = "             << res << '\n'
         << "computation takes "    << time_span.count() << " seconds\n";

    return 0;
}
