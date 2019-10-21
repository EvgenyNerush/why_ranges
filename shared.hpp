#include <cmath>

// upper limit of the integration
const double tau = pow(1'000'001 * M_PI, 1/3.0);

// a part of a period of f(t) function at t = tau
const double dT = 0.1 * 2 * M_PI / (3 * tau * tau);

// function to integrate
double f(double t) {
    return 3 * t * t * sin(t * t * t);
}
