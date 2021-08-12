#ifndef VANILLA3_H
#define VANILLA3_H

#include "./payoffBridge.hpp"

class VanillaOption3 {
    
public:
    VanillaOption3(const PayOffBridge &ThePayOff_, double Expiry);
    double OptionPayOff(double Spot) const;
    double GetExpiry() const;
    
private:
    double expiry;
    PayOffBridge thePayOff;
};

#endif
