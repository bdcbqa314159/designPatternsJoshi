#include "../include/dpJoshi_bits/parameters.hpp"

Parameters::Parameters(const ParametersInner &innerObject){
    InnerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters &original){
    InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters &Parameters::operator=(const Parameters &original){
    
    if (this != &original){
        
//        delete InnerObjectPtr;
        InnerObjectPtr = original.InnerObjectPtr->clone();
    }
    
    return *this;
}

Parameters::~Parameters(){
//    delete InnerObjectPtr;
}

double Parameters::Mean(double t1, double t2) const {
    
    double total = Integral(t1, t2);
    return total/(t2-t1);
}

double Parameters::RootMeanSquare(double t1, double t2) const {
    double total = IntegralSquare(t1, t2);
    return total/(t2-t1);
}

ParametersConstant::ParametersConstant(double constant){
    
    Constant = constant;
    ConstantSquare = Constant*Constant;
}

std::shared_ptr<ParametersInner> ParametersConstant::clone()const {
    return  std::shared_ptr<ParametersInner>(new ParametersConstant(*this));
}

double ParametersConstant::Integral(double t1, double t2) const {
    return (t2-t1)*Constant;
}

double ParametersConstant::IntegralSquare(double t1, double t2) const {
    
    return (t2-t1)*ConstantSquare;
}
