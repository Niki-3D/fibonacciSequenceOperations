#ifndef FIB_H
#define FIB_H

#include <string>
#include <iostream>

class Fib {
private:
    std::string fib_representation;

    static std::string normalize(const std::string& representation);
    static int toDecimal(const std::string& representation);
    static std::string fromDecimal(int decimalValue);

public:
    Fib();
    Fib(const std::string& str);
    Fib(int decimalValue);
    Fib(const Fib& other);

    Fib operator+(const Fib& other) const;
    Fib operator&(const Fib& other) const;
    Fib operator|(const Fib& other) const;
    Fib operator^(const Fib& other) const;
    Fib operator<<(int shift) const;
    Fib& operator<<=(int shift);

    bool operator==(const Fib& other) const;
    bool operator!=(const Fib& other) const;
    bool operator<(const Fib& other) const;
    bool operator<=(const Fib& other) const;
    bool operator>(const Fib& other) const;
    bool operator>=(const Fib& other) const;

    size_t length() const;

    friend std::ostream& operator<<(std::ostream& os, const Fib& f);
};

// Utility functions
Fib Zero();
Fib One();

#endif // FIB_H
