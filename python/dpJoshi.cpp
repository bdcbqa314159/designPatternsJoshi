#include "../cpp/include/dpJoshi_bits/simpleMC.hpp"
#include "../cpp/include/dpJoshi_bits/payoff1.hpp"
#include "../cpp/include/dpJoshi_bits/payoff2.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

class PyPayOff : public PayOff {
public:
    using PayOff::PayOff; // Inherit constructors
    double operator()(double Spot) const override { PYBIND11_OVERLOAD_PURE_NAME(double, PayOff, "__call__", operator(), Spot); }
};


void init_MC(py::module &m){

    m.def("simpleMC1", &SimpleMonteCarlo1);
    m.def("simpleMC2", py::overload_cast<const PayOff1& , double , double , double , double , unsigned long >(&SimpleMonteCarlo2));
    
    m.def("simpleMC2", py::overload_cast<const PayOff&  ,double , double , double , double , unsigned long >(&SimpleMonteCarlo2));
}

void init_PayOff(py::module &m){
    
    py::class_<PayOff1> payoff1(m, "PayOff1");
    
    payoff1.def(py::init<double &, PayOff1::OptionType>())
    .def("__call__", &PayOff1::operator());
             
    py::enum_<PayOff1::OptionType>(payoff1, "OptionType")
        .value("call", PayOff1::OptionType::call)
        .value("put", PayOff1::OptionType::put)
        .export_values();
    
    
    /*
     
     Here we implemement the second class of PayOff with virtual inheritance
     Check the book for more information
     
     */
    
    py::class_<PayOff, PyPayOff> payoff(m, "PayOff");
    payoff.def(py::init<>())
    .def("__call__", &PayOff::operator());

    py::class_<PayOffCall> payoffCall(m, "PayOffCall", payoff);
    payoffCall.def(py::init<double &>());

    py::class_<PayOffPut> payoffPut(m, "PayOffPut", payoff);
    payoffPut.def(py::init<double &>());
    
}


