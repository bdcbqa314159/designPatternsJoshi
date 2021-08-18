#ifndef PAYOFFFORWARD_H
#define PAYOFFFORWARD_H

#include "./payoff3.hpp"

class PayOffForward : public PayOff3 {
    double Strike;
    
public:
    PayOffForward(double Strike);
    virtual double operator()(double Spot) const;
    virtual ~PayOffForward(){};
    virtual std::shared_ptr<PayOff3> clone() const;
};



#endif
