#include <pybind11/pybind11.h>
namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

//binding code.
PYBIND11_MODULE(example, m) {
    m.doc() = "pybind example";
    m.def("add", &add, "Function that adds two ints.");
}
