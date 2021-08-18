#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_MC(py::module &);
void init_PayOff(py::module &);
void init_Parameters(py::module &);
void init_Wrapper(py::module &);
void init_MCStatistics(py::module &);
void init_Random(py::module &);
void init_MJArray(py::module &);
void init_CashFlows(py::module &);
void init_PathDependent(py::module &);
void init_ExoticEngine(py::module &);
void init_Trees(py::module &);
void init_BS(py::module &);


namespace dpj {

PYBIND11_MODULE(dpJoshi, m) {
    // Optional docstring
    m.doc() = "Working on Design Patterns book of Mark Joshi with a python -> excel interface.";

    init_MC(m);
    init_PayOff(m);
    init_Parameters(m);
    init_Wrapper(m);
    init_MCStatistics(m);
    init_Random(m);
    init_MJArray(m);
    init_CashFlows(m);
    init_PathDependent(m);
    init_ExoticEngine(m);
    init_Trees(m);
    init_BS(m);

	}

}
