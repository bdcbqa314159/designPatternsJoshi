#ifndef VANILLA1_h
#define VANILLA1_h

#include "./payoff2.hpp"

class VanillaOption{
public:
    VanillaOption(PayOff &ThePayOff, double Expiry);
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;
    
private:
    double Expiry;
    PayOff &ThePayOff;
};


#endif
