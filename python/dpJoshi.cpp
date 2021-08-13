#include "../cpp/include/dpJoshi_bits/simpleMC.hpp"
#include "../cpp/include/dpJoshi_bits/payoff1.hpp"
#include "../cpp/include/dpJoshi_bits/payoff2.hpp"
#include "../cpp/include/dpJoshi_bits/payoff3.hpp"
#include "../cpp/include/dpJoshi_bits/vanilla1.hpp"
#include "../cpp/include/dpJoshi_bits/vanilla2.hpp"
#include "../cpp/include/dpJoshi_bits/payoffBridge.hpp"
#include "../cpp/include/dpJoshi_bits/vanilla3.hpp"
#include "../cpp/include/dpJoshi_bits/parameters.hpp"
#include "../cpp/include/dpJoshi_bits/mcStatistics.hpp"


#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>


namespace py = pybind11;

class PyPayOff : public PayOff {
public:
    using PayOff::PayOff; // Inherit constructors
    double operator()(double Spot) const override { PYBIND11_OVERLOAD_PURE_NAME(double, PayOff, "__call__", operator(), Spot); }
};

class PyPayOff3 : public PayOff3 {
public:
    using PayOff3::PayOff3; // Inherit constructors
    double operator()(double Spot) const override { PYBIND11_OVERLOAD_PURE_NAME(double, PayOff3, "__call__", operator(), Spot); }
    
    std::shared_ptr<PayOff3> clone() const override {
            auto self = py::cast(this);
            auto cloned = self.attr("clone")();

            auto keep_python_state_alive = std::make_shared<py::object>(cloned);
            auto ptr = cloned.cast<PyPayOff3*>();

            // aliasing shared_ptr: points to `A_trampoline* ptr` but refcounts the Python object
            return std::shared_ptr<PayOff3>(keep_python_state_alive, ptr);
        }

};

class PyParametersInner : public ParametersInner {
public:
    using ParametersInner::ParametersInner; // Inherit constructors

    std::shared_ptr<ParametersInner> clone() const override {
            auto self = py::cast(this);
            auto cloned = self.attr("clone")();

            auto keep_python_state_alive = std::make_shared<py::object>(cloned);
            auto ptr = cloned.cast<PyParametersInner*>();

            // aliasing shared_ptr: points to `A_trampoline* ptr` but refcounts the Python object
            return std::shared_ptr<ParametersInner>(keep_python_state_alive, ptr);
        }
    
    double Integral(double t1, double t2) const override { PYBIND11_OVERLOAD_PURE(double, PyParametersInner, Integral, t1, t2); }
    
    double IntegralSquare(double t1, double t2) const override { PYBIND11_OVERLOAD_PURE(double, PyParametersInner, IntegralSquare, t1, t2); }
    
};

class PyStatisticsMC: public StatisticsMC {
    
public:
    using StatisticsMC::StatisticsMC;
    
    void DumpOneResult(double result) override {
        PYBIND11_OVERLOAD_PURE(void, PyStatisticsMC, DumpOneResult, result);
    }
    
    std::vector<std::vector <double>> GetResultsSoFar() const override {PYBIND11_OVERLOAD_PURE(std::vector<std::vector <double>>, PyStatisticsMC, GetResultsSoFar, );
    }
    
    std::shared_ptr<StatisticsMC> clone() const override {
            auto self = py::cast(this);
            auto cloned = self.attr("clone")();

            auto keep_python_state_alive = std::make_shared<py::object>(cloned);
            auto ptr = cloned.cast<PyStatisticsMC*>();

            // aliasing shared_ptr: points to `A_trampoline* ptr` but refcounts the Python object
            return std::shared_ptr<StatisticsMC>(keep_python_state_alive, ptr);
        }
};

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
    
    py::class_<PayOffDoubleDigital> payoffDD(m, "PayOffDD", payoff);
    payoffDD.def(py::init<double &, double &>());
    
    py::class_<VanillaOption> vanilla1(m, "Vanilla1");
    vanilla1.def(py::init<PayOff &, double &>());
    vanilla1.def(py::init<VanillaOption &>());
    
    py::class_<PayOff3, PyPayOff3> payoff3(m, "PayOff3");
    payoff3.def(py::init<>())
    .def("__call__", &PayOff3::operator());

    py::class_<PayOffCall3> payoffCall3(m, "PayOffCall3", payoff3);
    payoffCall3.def(py::init<double &>());

    py::class_<PayOffPut3> payoffPut3(m, "PayOffPut3", payoff3);
    payoffPut3.def(py::init<double &>());
    
    py::class_<PayOffDoubleDigital3> payoffDD3(m, "PayOffDD3", payoff3);
    payoffDD3.def(py::init<double &, double &>());
    
    py::class_<VanillaOption2> vanilla2(m, "Vanilla2");
    vanilla2.def(py::init<PayOff3 &, double &>());
    vanilla2.def(py::init<const VanillaOption2 &>());
    
    
    py::class_<PayOffBridge> payoffBridge(m, "PayOffBridge");
    payoffBridge.def(py::init<const PayOffBridge &>());
    payoffBridge.def(py::init<const PayOff3 &>());
    
    py::class_<VanillaOption3> vanilla3(m, "Vanilla3");
    vanilla3.def(py::init<const PayOffBridge &, double &>());
}


void init_MC(py::module &m){

    m.def("simpleMC1", &SimpleMonteCarlo1);
    m.def("simpleMC2", py::overload_cast<const PayOff1& , double , double , double , double , unsigned long >(&SimpleMonteCarlo2));
    
    m.def("simpleMC2", py::overload_cast<const PayOff&  ,double , double , double , double , unsigned long >(&SimpleMonteCarlo2));
    
    m.def("simpleMC3", &SimpleMonteCarlo3);
    m.def("simpleMC4", &SimpleMonteCarlo4);
    m.def("simpleMC5", &SimpleMonteCarlo5);
    m.def("simpleMC6", &SimpleMonteCarlo6);
    m.def("simpleMC7", &SimpleMonteCarlo7);
}


void init_Parameters(py::module &m){
    
    py::class_<ParametersInner, PyParametersInner> parametersInner(m, "ParametersInner");
    parametersInner.def(py::init<>());

    py::class_<ParametersConstant> parametersConstant(m, "ParametersConstant", parametersInner);
    parametersConstant.def(py::init<double &>());
    
    py::class_<Parameters> parameters(m, "Parameters");
    parameters.def(py::init<const ParametersInner &>());
    parameters.def(py::init<const Parameters &>());
}


void init_MCStatistics(py::module &m){
    
    py::class_<StatisticsMC, PyStatisticsMC> statisticsmc(m, "StatisticsMC");
    statisticsmc.def(py::init<>());

    py::class_<StatisticsMean> statisticsmean(m, "StatisticsMean", statisticsmc);
    statisticsmean.def(py::init<>());
    statisticsmean.def("GetResultSoFar", [](StatisticsMean &self){py::array out = py::cast(self.GetResultsSoFar());
        return out;
    });
    
}
