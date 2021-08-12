#include "../include/dpJoshi_bits/vanilla3.hpp"

VanillaOption3::VanillaOption3(const PayOffBridge &ThePayOff_, double Expiry_)
: thePayOff(ThePayOff_), expiry(Expiry_){
    
}

double VanillaOption3::GetExpiry() const {
    
    return expiry;
}

double VanillaOption3::OptionPayOff(double Spot) const {
    
    return thePayOff(Spot);
}
