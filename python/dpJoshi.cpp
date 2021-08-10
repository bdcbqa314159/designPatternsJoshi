#include "../cpp/include/dpJoshi_bits/simpleMC.hpp"
#include "../cpp/include/dpJoshi_bits/payoff1.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void init_MC(py::module &m){

    m.def("simpleMC1", &SimpleMonteCarlo1);
    m.def("simpleMC2", &SimpleMonteCarlo2);

}

void init_PayOff(py::module &m){
    
    py::class_<PayOff> payoff(m, "PayOff");
    payoff.def(py::init<double &, PayOff::OptionType>())
    .def("__call__", &PayOff::operator());
             
    py::enum_<PayOff::OptionType>(payoff, "OptionType")
        .value("call", PayOff::OptionType::call)
        .value("put", PayOff::OptionType::put)
        .export_values();
}
