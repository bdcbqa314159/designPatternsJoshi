#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_MC(py::module &);
void init_PayOff(py::module &);
void init_Parameters(py::module &);
void init_MCStatistics(py::module &);


namespace dpj {

PYBIND11_MODULE(dpJoshi, m) {
    // Optional docstring
    m.doc() = "Working on Design Patterns book of Mark Joshi with a python -> excel interface.";

    init_MC(m);
    init_PayOff(m);
    init_Parameters(m);
    init_MCStatistics(m);

	}

}
