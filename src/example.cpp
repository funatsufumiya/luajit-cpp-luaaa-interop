#include "example.h"
#include <string>
#include <iostream>

double Calculator::add(double a, double b) {
    std::cout << "C++ add called with: " << a << ", " << b << std::endl;
    return a + b;
}

double Calculator::multiply(double a, double b) {
    std::cout << "C++ multiply called with: " << a << ", " << b << std::endl;
    return a * b;
}

const char* Calculator::greet(const char* name) {
    static std::string result;
    result = "Hello, " + std::string(name) + "!";
    return result.c_str();
}
