# why_ranges

Here we compute $ 3 \int_0^\tau t^2 \sin t^3 \, dt = 2$ (LaTeX notation) numerically with different
methods to answer the following question: are the C++20 ranges suitable to be used as unevenly
distributed nodes of trapezoidal rule of integration?

To compile `v4.cpp` and `v5.cpp` one need to copy/clone
[range-v3](https://github.com/ericniebler/range-v3) source into `range-v3` folder.

### v1.cpp

Integration with a plain `for` loop, with a fixed timestep of a small part of a period of the sine
function at $ t = \tau $ (which is $ \Delta t = 2 \pi / (3 \tau^2) $).

### v2.cpp

The same as `v1`, but the nodes are stored in a `std::vector` first.

### v3.cpp

Instead of the use of `std::vector`, a lazy container is used that computes the value of $ t $
every time when `++` is called for it.

### v4.cpp

`iota_view` and `transform` from `ranges-v3` are used instead of the iterator.

## Results

