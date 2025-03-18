#include "fib.h"

// --- Utility helpers ---

std::string Fib::normalize(const std::string& representation) {
    int decimalValue = toDecimal(representation);
    return fromDecimal(decimalValue);
}

int Fib::toDecimal(const std::string& representation) {
    int sum = 0;
    int previousFibonacci = 1, currentFibonacci = 2;

    for (int index = representation.size() - 1; index >= 0; --index) {
        if (representation[index] == '1') {
            sum += previousFibonacci;
        }
        int nextFibonacci = previousFibonacci + currentFibonacci;
        previousFibonacci = currentFibonacci;
        currentFibonacci = nextFibonacci;
    }

    return sum;
}

std::string Fib::fromDecimal(int decimalValue) {
    if (decimalValue == 0) return "0";

    std::string result;
    int previousFibonacci = 1, currentFibonacci = 2;

    while (currentFibonacci <= decimalValue) {
        int nextFibonacci = previousFibonacci + currentFibonacci;
        previousFibonacci = currentFibonacci;
        currentFibonacci = nextFibonacci;
    }

    bool foundFirstOne = false;
    while (previousFibonacci > 0) {
        if (decimalValue >= currentFibonacci) {
            result += '1';
            decimalValue -= currentFibonacci;
            foundFirstOne = true;
        } else if (foundFirstOne) {
            result += '0';
        }

        int nextFibonacci = currentFibonacci - previousFibonacci;
        currentFibonacci = previousFibonacci;
        previousFibonacci = nextFibonacci;
    }

    return result;
}

// --- Constructors ---

Fib::Fib() : fib_representation("0") {}

Fib::Fib(const std::string& stringRepresentation) {
    std::string cleanedRepresentation = stringRepresentation;
    cleanedRepresentation.erase(0, cleanedRepresentation.find_first_not_of('0'));
    fib_representation = cleanedRepresentation.empty() ? "0" : cleanedRepresentation;
}

Fib::Fib(int decimalValue) {
    fib_representation = fromDecimal(decimalValue);
}

Fib::Fib(const Fib& other) : fib_representation(other.fib_representation) {}

// --- Core operations ---

Fib Fib::operator+(const Fib& other) const {
    int leftDecimal = toDecimal(this->fib_representation);
    int rightDecimal = toDecimal(other.fib_representation);
    return Fib(fromDecimal(leftDecimal + rightDecimal));
}

Fib Fib::operator&(const Fib& other) const {
    std::string leftRepresentation = normalize(this->fib_representation);
    std::string rightRepresentation = normalize(other.fib_representation);
    std::string result;

    if (leftRepresentation.size() < rightRepresentation.size()) {
        leftRepresentation.insert(0, rightRepresentation.size() - leftRepresentation.size(), '0');
    } else if (leftRepresentation.size() > rightRepresentation.size()) {
        rightRepresentation.insert(0, leftRepresentation.size() - rightRepresentation.size(), '0');
    }

    for (size_t index = 0; index < leftRepresentation.size(); ++index) {
        result += (leftRepresentation[index] == '1' && rightRepresentation[index] == '1') ? '1' : '0';
    }

    return Fib(result.empty() ? "0" : result);
}

Fib Fib::operator|(const Fib& other) const {
    std::string leftRepresentation = normalize(this->fib_representation);
    std::string rightRepresentation = normalize(other.fib_representation);
    std::string result;

    if (leftRepresentation.size() < rightRepresentation.size()) {
        leftRepresentation.insert(0, rightRepresentation.size() - leftRepresentation.size(), '0');
    } else if (leftRepresentation.size() > rightRepresentation.size()) {
        rightRepresentation.insert(0, leftRepresentation.size() - rightRepresentation.size(), '0');
    }

    for (size_t index = 0; index < leftRepresentation.size(); ++index) {
        result += (leftRepresentation[index] == '1' || rightRepresentation[index] == '1') ? '1' : '0';
    }
    return Fib(result);
}

Fib Fib::operator^(const Fib& other) const {
    std::string leftRepresentation = normalize(this->fib_representation);
    std::string rightRepresentation = normalize(other.fib_representation);
    std::string result;

    if (leftRepresentation.size() < rightRepresentation.size()) {
        leftRepresentation.insert(0, rightRepresentation.size() - leftRepresentation.size(), '0');
    } else if (leftRepresentation.size() > rightRepresentation.size()) {
        rightRepresentation.insert(0, leftRepresentation.size() - rightRepresentation.size(), '0');
    }

    for (size_t index = 0; index < leftRepresentation.size(); ++index) {
        result += (leftRepresentation[index] != rightRepresentation[index]) ? '1' : '0';
    }
    return Fib(result);
}

Fib Fib::operator<<(int shiftAmount) const {
    std::string shiftedRepresentation = this->fib_representation;
    shiftedRepresentation.append(shiftAmount, '0');
    return Fib(shiftedRepresentation);
}

Fib& Fib::operator<<=(int shiftAmount) {
    this->fib_representation.append(shiftAmount, '0');
    return *this;
}

// --- Comparisons ---

bool Fib::operator==(const Fib& other) const {
    return normalize(this->fib_representation) == normalize(other.fib_representation);
}

bool Fib::operator!=(const Fib& other) const {
    return !(*this == other);
}

bool Fib::operator<(const Fib& other) const {
    return toDecimal(this->fib_representation) < toDecimal(other.fib_representation);
}

bool Fib::operator<=(const Fib& other) const {
    return toDecimal(this->fib_representation) <= toDecimal(other.fib_representation);
}

bool Fib::operator>(const Fib& other) const {
    return toDecimal(this->fib_representation) > toDecimal(other.fib_representation);
}

bool Fib::operator>=(const Fib& other) const {
    return toDecimal(this->fib_representation) >= toDecimal(other.fib_representation);
}

size_t Fib::length() const {
    return normalize(fib_representation).length();
}

std::ostream& operator<<(std::ostream& outputStream, const Fib& fibonacciNumber) {
    return outputStream << Fib::normalize(fibonacciNumber.fib_representation);
}

// --- Utilities ---

Fib Zero() {
    return Fib("0");
}

Fib One() {
    return Fib("1");
}
