#include "../fib.h"

#include <cassert>
#include <iostream>

int main() {
    assert(Fib() == Zero());
    assert(Fib() >= Zero());
    assert(Fib() <= Zero());
    assert(!(Fib() != Zero()));
    assert(!(Fib() > Zero()));
    assert(!(Fib() < Zero()));

    assert(Zero() != One());
    assert(Zero() < One());
    assert(Zero() <= One());
    assert(!(Zero() == One()));
    assert(!(Zero() > One()));
    assert(!(Zero() >= One()));

    assert(Fib("11") == Fib("100"));
    assert(Fib("11011") == Fib("100100"));
    assert(Fib("111") == Fib("1001"));
    assert(Fib("1111") == Fib("10100"));
    assert(Fib("11111") == Fib("101001"));
    assert(Fib("100001100") == Fib("100010000"));
    assert(Fib("100011") > Fib("100010"));
    assert(Fib("11000") > Fib("10011"));
    assert(Fib("10100") < Fib("100100"));
    assert(Fib("11") < Fib("100000"));

    assert(Fib(0) == Zero());
    assert(Fib(1) == One());
    assert(Fib(2) == Fib("10"));
    assert(Fib(3) == Fib("11"));
    assert(Fib(10) == Fib("10010"));
    assert(Fib(123456789) == Fib("100010100000101010000010100100000101001"));

    Fib f(2);
    assert(f >= Fib(2));
    assert(Fib(2) >= f);
    assert(f <= Fib(2));
    assert(Fib(2) <= f);
    assert(f > Fib(1));
    assert(f < Fib(3));
}