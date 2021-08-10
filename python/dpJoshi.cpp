#include "../cpp/include/quantFiOop_bits/intro.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void init_say(py::module &m){

    m.def("say", &say);//, py::arg("msg"));
}

