#include "fib.h"

#include <cassert>
#include <iostream>

int main() {
    assert((Zero() + Zero()) == Zero());
    assert((Zero() + One()) == One());
    assert((One() + Zero()) == One());

    assert((One() + One()) == Fib("10"));
    assert((Fib("1") + Fib("10000")) == Fib("10001"));
    assert((Fib("10000") + Fib("1")) == Fib("10001"));
    assert((Fib("10010") + Fib("100010")) == Fib("1000101"));
    assert((Fib("10101") + Fib("1010")) == Fib("101001"));
    assert((Fib("1000101") + Fib("1000101")) == Fib("10100100"));

    Fib f(Zero());
    assert(f == Zero());
    assert((f + One()) == One());
    assert(f == Zero());

    f = Fib("1") + Fib("10") + Fib("100");
    assert(f == Fib("1001"));

    // f = Fib("101");
    // f += f;
    // assert(f == Fib("10000"));
    // f += f += f;
    // assert(f == Fib("1010100"));
    //
    // f = f;
    // assert(f == Fib("1010100"));
}