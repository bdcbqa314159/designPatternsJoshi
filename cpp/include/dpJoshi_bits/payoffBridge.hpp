#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "./payoff3.hpp"

class PayOffBridge {
public:
    PayOffBridge(const PayOffBridge &original);
    PayOffBridge(const PayOff3 &innerPayOff);
    
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge &operator=(const PayOffBridge &original);
    
private:
//    PayOff3 *thePayOffPtr;
    std::shared_ptr<PayOff3> thePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const{
    return thePayOffPtr->operator()(Spot);
}

#endif
