#include <iostream>
#include <chrono>
#include "shared.hpp"

using namespace std;
using namespace std::chrono;

// trapezoidal rule of integration with fixed time step
template <typename T>
double integrate(T t_nodes) {
    double acc = 0;
    for(auto t: t_nodes) {
        acc += dt_fixed * f(t);
    }
    acc -= 0.5 * dt_fixed * f(0);
    acc -= 0.5 * dt_fixed * f(tau);
    return acc;
}

class lazy_container {
    public:
        long long int n_nodes;
        lazy_container() {
            n_nodes = n_fixed;
        }
        ~lazy_container() {}
        class iterator {
            public:
                long long int i; // index of the current node
                iterator() {
                    i = 0;
                }
                ~iterator() {}
                iterator& operator++()                          { i+= 1; return *this; }
                bool      operator!=(const iterator& rhs) const { return i != rhs.i; }
                double    operator* ()                    const
                    { return dt_fixed * static_cast<double>(i); }
        };
        iterator begin() {
            return iterator();
        }
        iterator end() {
            iterator it;
            it.i = n_nodes;
            return it;
        }
};

int main() {
    steady_clock::time_point t1 = steady_clock::now();

    lazy_container t_nodes;
    double res = integrate(t_nodes);

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "\x1b[32mv3\x1b[0m\n"
         << "number of timesteps: " << n_fixed           << '\n'
         << "result = "             << res               << '\n'
         << "computation takes "    << time_span.count() << " seconds\n";

    return 0;
}
