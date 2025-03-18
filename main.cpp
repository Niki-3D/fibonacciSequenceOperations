#include "fib.h"
#include <cassert>
#include <iostream>

int main() {
    Fib f;

    assert(f == Zero());
    assert(Fib(f) == Zero());
    assert(Zero() < One());
    assert(Fib("11") == Fib("100"));
    assert((Fib("1001") + Fib("10")) == Fib("1011"));
    assert((Fib("1001") & Fib("1100")) == Zero()); // 1100 == 10000
    assert((Fib("1100") | Fib("11")) == Fib("10100")); // 1100 == 10000, 11 == 100
    assert((Fib("1001") ^ Fib("1010")) == Fib("11"));
    assert((Fib("101") << 3) == Fib("101000"));

    f = One();
    f <<= 3;
    assert(f == Fib("1000"));

    f = One();
    assert(f + Fib("1") == Fib("10"));
    assert(f == One());

    Fib f1("101");
    Fib f2 = Fib("101");
    assert(f1 == f2);

    assert(Fib("11").length() == 3); // 11 == 100

    std::cout << Fib("11") << std::endl; // wyświetla 100

    std::cout << "Wszystkie testy przeszły poprawnie!" << std::endl;
    return 0;
}
