# why_ranges

Here we compute $ 3 \int_0^\tau t^2 \sin t^3 \, dt = 2$ (LaTeX notation) numerically with different
methods to answer the following question: are the C++20 ranges suitable to be used as unevenly
distributed nodes of trapezoidal rule of integration?

###v1.cpp

Integration with a plain `for` loop, with a fixed timestep of a small part of a period of the sine
function at $ t = \tau $ (wich is $ \Delta t = 2 \pi / (3 \tau^2) $).

###v2.cpp

The same as `v1`, but the nodes are stored in a `std::vector` first.

##Results

v2 is faster than v1?
