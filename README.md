# why_ranges

Here we compute $ 3 \int_0^\tau t^2 \sin t^3 \, dt = 2$ (LaTeX notation) numerically with different
methods to answer the following question: are the C++20 ranges suitable to be used as unevenly
distributed nodes of trapezoidal rule of integration?

To compile `v4.cpp` and `v5.cpp` one need to copy/clone
[range-v3](https://github.com/ericniebler/range-v3) source into this folder.

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

### v5.cpp

`ranges-v3` are used, but the timestep is non-constant.

## Results

For Xeon X5550, time in seconds.

O3, ffast-math:

<table>
    <tr>
        <td></td>        <td>v1</td>  <td>v2</td>  <td>v3</td>  <td>v4</td>  <td>v5</td>
    </tr>
    <tr>
        <td>g++</td>     <td>4.7</td> <td>6.7</td> <td>4.6</td> <td>3.7</td> <td>4.3</td>
    </tr>
    <tr>
        <td>clang++</td> <td>5.0</td> <td>7.2</td> <td>4.6</td> <td>4.8</td> <td>4.1</td>
    </tr>
</table>

debug mode:

<table>
    <tr>
        <td></td>        <td>v1</td>  <td>v2</td>   <td>v3</td>  <td>v4</td>   <td>v5</td>
    </tr>
    <tr>
        <td>g++</td>     <td>5.9</td> <td>17.8</td> <td>7.2</td> <td>33.6</td> <td>14.3</td>
    </tr>
</table>
