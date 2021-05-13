#include "xoshiro256ss.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>

constexpr bool test() {
    xoshiro256ss x(100);
    assert(x() == 792317387143481937uLL);
    assert(x() == 1418856489092323125uLL);
    assert(x() == 6662743737787356053uLL);
    assert(x() == 9823178768685107703uLL);
    return true;
}
static_assert(test(), "compile-time OK");

void shuffle_example() {
    int cards[52] {};
    xoshiro256ss g;
    std::shuffle(cards, cards + 52, g);
    (void) std::uniform_int_distribution<int>(1,6)(g);
    (void) std::uniform_real_distribution<float>(1,6)(g);
}

int main() {
    xoshiro256ss x(100);
    std::cout << x() << '\n';
    std::cout << x() << '\n';
    std::cout << x() << '\n';
    std::cout << x() << '\n';

    test();
    shuffle_example();
}
