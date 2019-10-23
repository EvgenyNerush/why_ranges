#include <iostream>
#include <chrono>
#include <range/v3/view/drop.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/transform.hpp>

#include "shared.hpp"

using namespace std;
using namespace std::chrono;

// approximate number of periods (oscillations) of f on the interval [0, \tau^3]
double periods = tau * tau * tau / (2 * M_PI);
// number of steps for numerical integration; e.g., a = 0.1 yields 10 steps per period
long long int n = static_cast<long long int>(periods / a);

// trapezoidal rule of integration; step size is not fixed
template <typename T>
double integrate(T t_nodes) {
    double acc = 0;
    double t_prev = *(t_nodes.begin());
    double f_prev = f(t_prev);
    for (auto t: t_nodes | ranges::v3::views::drop(1)) {
        double f_curr = f(t);
        acc += 0.5 * (t - t_prev) * (f_curr + f_prev);
        t_prev = t;
        f_prev = f_curr;
    }
    return acc;
}

int main() {
    steady_clock::time_point t1 = steady_clock::now();

    // this function ensures the timestep(t) such that for some beginning points the timestep ~ a,
    // and then the timestep depend on time in the same way as the oscillation period,
    // timestep(t) ~ a / t^2
    auto step_f = [](long long i) {
            if (static_cast<double>(i) <= 1 / a) {
                return pow(2 * M_PI, 1/3.0) * a * static_cast<double>(i);
            } else {
                return tau * pow(static_cast<double>(i) / static_cast<double>(n), 1/3.0);
            }
        };
    auto t_nodes = ranges::v3::iota_view(0, n)
                 | ranges::v3::views::transform(step_f);
    double res = integrate(t_nodes);

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "\x1b[32mv5\x1b[0m\n"
         << "number of timesteps: " << n   << '\n'
         << "result = "             << res << '\n'
         << "computation takes "    << time_span.count() << " seconds\n";

    return 0;
}
