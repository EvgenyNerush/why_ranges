#include <cmath>

// function to integrate
double f(double t) {
    return 3 * t * t * sin(t * t * t);
}

// upper limit of the integration
const double tau = pow(10'000'001 * M_PI, 1/3.0);

const double a = 0.1;

// a part of a period of f(t) function at t = tau
const double dT = a * 2 * M_PI / (3 * tau * tau);

// number of intervals for numerical integration with fixed time step
long long n_fixed = llround(tau / dT);

// time step which do not depend on the step number
double dt_fixed = tau / static_cast<double>(n_fixed - 1);
