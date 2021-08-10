#include "../cpp/include/dpJoshi_bits/simpleMC.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void init_MC(py::module &m){

    m.def("simpleMC", &SimpleMonteCarlo1);//, py::arg("msg"));
}

