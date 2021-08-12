#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <memory>

class ParametersInner {
    
public:
    ParametersInner(){}
    
//    virtual ParametersInner *clone() const = 0;
    virtual std::shared_ptr<ParametersInner> clone() const=0;
    virtual double Integral(double t1, double t2) const = 0;
    virtual double IntegralSquare(double t1, double t2) const = 0;
    virtual ~ParametersInner(){}

private:
};

class Parameters {
    
public:
    Parameters(const ParametersInner &innerObject);
    Parameters(const Parameters &original);
    Parameters &operator=(const Parameters &original);
    virtual ~Parameters();
    
    inline double Integral(double t1, double t2) const;
    inline double IntegralSquare(double t1, double t2) const;
    
    double Mean(double t1, double t2) const;
    double RootMeanSquare(double t1, double t2) const;
    
private:
//    ParametersInner *InnerObjectPtr;
    std::shared_ptr<ParametersInner> InnerObjectPtr;
};

inline double Parameters::Integral(double t1, double t2) const {
    return InnerObjectPtr->Integral(t1, t2);
}

inline double Parameters::IntegralSquare(double t1, double t2) const {
    return InnerObjectPtr->IntegralSquare(t1, t2);
}

class ParametersConstant : public ParametersInner {
    
public:
    ParametersConstant(double constant);
    
//    virtual ParametersInner *clone() const;
    virtual std::shared_ptr<ParametersInner> clone() const;
    virtual double Integral(double t1, double t2) const;
    virtual double IntegralSquare(double t1, double t2) const;
    
private:
    double Constant;
    double ConstantSquare;
};



#endif
