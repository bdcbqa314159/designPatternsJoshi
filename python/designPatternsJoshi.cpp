#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_say(py::module &);

namespace qf {

PYBIND11_MODULE(quantFiOop, m) {
    // Optional docstring
    m.doc() = "Working on a Quantitative Finance - an OOP approach in C++";

    init_say(m);

	}

}
