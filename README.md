A minimal xoshiro256** generator, with the C++ <random> interface.

Generate 64-bit random integers, speedily, with code small enough to
paste directly into your project.

By Arthur O'Dwyer, based on code by David Blackman and Sebastiano Vigna.
All errors are my own.
Public domain.

* https://prng.di.unimi.it/xoshiro256starstar.c

* https://prng.di.unimi.it/splitmix64.c

## Test vectors

Initialize `xoshiro256**` with the SplitMix64 of seed `100`, then
generate four 64-bit results; they should be

    792317387143481937
    1418856489092323125
    6662743737787356053
    9823178768685107703

or, in hex,

    0afee077'3a0d8a51
    13b0ca75'9b9b1735
    5c76d220'f8461395
    8852f10b'70a289f7

In this repository, `test-vector.cpp` uses this C++ `xoshiro256ss.h` implementation;
`test-vector.c` uses Blackman and Vigna's C code; and `test-vector.py` uses the
implementation from the Python `randomgen` package. All three produce the expected
output on my machine.
