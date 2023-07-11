#include <pybind11/pybind11.h>
#include <bits/stdc++.h>
#include <iostream>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

int sub(int i, int j) {
    return i - j;
}

int powerof3(int k) {
    return pow(3, k);
}

long long factorial(int x) {
    long long res = 1;
    for (int i = 1; i <= x; i++) {
        res *= i;
    }
    return res;
}
//binding code.
PYBIND11_MODULE(example, m) {
    m.doc() = "pybind example";
    m.def("add", &add, "Function that adds two ints.");
    m.def("subtract", &sub, "Subtraction function.");
    m.def("powerof3", &powerof3, "power of 3 function.");
    m.def("factorial", &factorial);
}
