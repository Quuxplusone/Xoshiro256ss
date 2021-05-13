#!/usr/bin/env python

import randomgen

# https://bashtage.github.io/randomgen/bit_generators/xoshiro256.html

for i in randomgen.xoshiro256.Xoshiro256(100, mode="legacy").random_raw(4):
    print(i)
