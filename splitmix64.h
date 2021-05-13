#pragma once

// The "splitmix64" generator.
// C++ port by Arthur O'Dwyer (2021).
// Based on the C version by Sebastiano Vigna (2015),
// https://prng.di.unimi.it/splitmix64.c

static_assert(sizeof(long long) == 8, "64-bit machines only");

struct splitmix64 {
    using u64 = unsigned long long;
    u64 x;

    constexpr explicit splitmix64(u64 seed) : x(seed) {}

    using result_type = u64;
    static constexpr u64 min() { return 0; }
    static constexpr u64 max() { return u64(-1); }

    constexpr u64 operator()() {
        u64 z = (x += 0x9e3779b97f4a7c15uLL);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9uLL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebuLL;
        return z ^ (z >> 31);
    }
};
