#ifndef PAYOFF3_H
#define PAYOFF3_H
#include <algorithm>
#include <memory.h>

class PayOff3 {
    
public:
    PayOff3(){};
    
    virtual double operator()(double Spot) const=0;
    virtual ~PayOff3(){}
//    virtual PayOff3 *clone() const=0;
    virtual std::shared_ptr<PayOff3> clone() const=0;
    
private:
    
};

class PayOffCall3 :public PayOff3 {
    
public:
    PayOffCall3(double Strike_);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall3(){}
//    virtual PayOff3 *clone() const;
    virtual std::shared_ptr<PayOff3> clone() const;
    

private:
    double Strike;
};

class PayOffPut3 :public PayOff3 {
    
public:
    PayOffPut3(double Strike_);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut3(){}
//    virtual PayOff3 *clone() const;
    virtual std::shared_ptr<PayOff3> clone() const;

private:
    double Strike;
};

class PayOffDoubleDigital3 : public PayOff3 {
    
public:
    PayOffDoubleDigital3(double LowerLevel, double UpperLevel);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital3(){}
//    virtual PayOff3 *clone() const;
    virtual std::shared_ptr<PayOff3> clone() const;
    
private:
    double LowerLevel;
    double UpperLevel;
};



#endif
