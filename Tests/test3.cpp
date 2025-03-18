#include "../fib.h"

#include <cassert>
#include <iostream>

int main() {
    assert((Zero() | Zero()) == Zero());
    assert((Zero() & Zero()) == Zero());
    assert((Zero() ^ Zero()) == Zero());

    assert((Zero() | One()) == One());
    assert((Zero() & One()) == Zero());
    assert((Zero() ^ One()) == One());

    Fib a;

    a = Fib("101010") & Fib("10101");
    assert(a == Zero());
    a = Fib("101010") | Fib("10101");
    assert(a == Fib("1001111"));
    a = Fib("101010") ^ Fib("10101");
    assert(a == Fib("1010100"));

    assert((Fib("1001") & Fib("1010")) == Fib("1000"));
    assert((Fib("1001") | Fib("1010")) == Fib("1011"));
    assert((Fib("1001") ^ Fib("1010")) == Fib("11"));

    a = Fib("1") & Fib("100000");
    assert(a == Zero());
    assert(a.length() == 1);
    a = Fib("100000") & Fib("1");
    assert(a == Zero());
    assert(a.length() == 1);

    assert((Fib("1") | Fib("100000")) == Fib("100001"));
    assert((Fib("100000") | Fib("1")) == Fib("100001"));

    assert((Fib("1") ^ Fib("100000")) == Fib("100001"));
    assert((Fib("100000") ^ Fib("1")) == Fib("100001"));

    assert((Fib("0") & Fib("100000")) == Zero());
    assert((Fib("100000") & Fib("0")) == Zero());

    assert((Fib("0") | Fib("100000")) == Fib("100000"));
    assert((Fib("100000") | Fib("0")) == Fib("100000"));

    assert((Fib("0") ^ Fib("100000")) == Fib("100000"));
    assert((Fib("100000") ^ Fib("0")) == Fib("100000"));

    Fib f(One());
    assert ((f & Zero()) == Zero());
    assert(f == One());
    assert((f | Fib("10")) == Fib("11"));
    assert(f == One());
    assert((f ^ One()) == Zero());
    assert(f == One());

    assert((Fib() << 0) == Zero());
    assert((Fib() << 100) == Zero());

    assert((Fib("1") << 0) == One());
    assert(((Fib("1") << 3) << 5) == (Fib("1") << 8));
    a = Fib("1") << 5;
    assert(a == Fib("100000"));

    assert((Fib("101") << 3) == Fib("101000"));
    assert((Fib("11") << 3) == Fib("11000"));

    Fib f2(One());
    assert((f2 << 1) == Fib("10"));
    assert(f2 == One());

    // f = Fib("101");
    // f ^= Fib("1");
    // assert(f == Fib("100"));
    // f ^= f ^= f;
    // // assert(f == Fib("0"));
    //
    // f = Fib("100");
    // f |= Fib("1");
    // assert(f == Fib("101"));
    // f |= f |= f;
    // assert(f == Fib("101"));
    //
    // f = Fib("100");
    // f &= Fib("101");
    // assert(f == Fib("100"));
    // f &= f &= f;
    // assert(f == Fib("100"));
}