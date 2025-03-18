# Fibonacci Number System Implementation

## Overview
This project implements a class `Fib` that represents numbers in the Fibonacci number system. The Fibonacci number system is a numeral system where each number is represented as a sum of distinct, non-consecutive Fibonacci numbers.

### Fibonacci Sequence:
```
F_1 = 1
F_2 = 1
F_n = F_(n-1) + F_(n-2) for n > 2
```

### Fibonacci Number System:
Each number can be uniquely represented in a binary-like format where each digit corresponds to a Fibonacci number. However, the representation must be normalized so that no two consecutive `1`s appear.

For example:
```
1000101 = F_8 + F_4 + F_2 = 21 + 3 + 1 = 25
10010010 = F_9 + F_6 + F_3 = 34 + 8 + 2 = 44
```

Since:
```
100 = F_4 = 3
11 = F_3 + F_2 = 2 + 1 = 3
```
we enforce that no two `1`s appear consecutively.

---

## Class `Fib` Implementation

### Constructors:
- `Fib()` – Creates a number with value `0`.
- `Fib(std::string str)` – Creates a number from its Fibonacci representation (even if not normalized).
- `Fib(int n)` – Creates a number from an integer value.
- `Fib(const Fib& f)` – Copy constructor.

### Assignment:
- `f1 = f2` – Assigns the value of `f2` to `f1`.

### Arithmetic Operations:
- `f1 + f2` – Adds two Fibonacci numbers.

### Bitwise Operations (performed in Fibonacci number system):
- `f1 & f2` – Bitwise AND.
- `f1 | f2` – Bitwise OR.
- `f1 ^ f2` – Bitwise XOR.
- `f << n` – Left shift by `n` positions.

### Comparison Operations:
- `f1 op f2` – Supports `==, <, <=, !=, >, >=` based on their integer values.

### Utility Functions:
- `f.length()` – Returns the length of the normalized Fibonacci representation.
- `os << f` – Outputs `f` in normalized Fibonacci representation.

### Global Functions:
- `Zero()` – Returns an immutable object representing `0`.
- `One()` – Returns an immutable object representing `1`.

---

## Example Usage

```cpp
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

    std::cout << Fib("11") << std::endl; // Outputs 100
}
```

---

## Compilation and Usage
To compile the project, use a C++ compiler that supports C++11 or newer.

---

