#ifndef VANILLA2_H
#define VANILLA2_H

#include "./payoff3.hpp"

class VanillaOption2 {
    
public:
    VanillaOption2(const PayOff3 &ThePayOff_, double Expiry_);
    VanillaOption2(const VanillaOption2 &orginal);
    VanillaOption2 &operator=(const VanillaOption2 &original);
    ~VanillaOption2();
    
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;
    
private:
    double Expiry;
    std::shared_ptr<PayOff3> ThePayOffPtr;
};

#endif

