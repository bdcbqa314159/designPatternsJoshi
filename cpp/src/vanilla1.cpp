#include "../include/dpJoshi_bits/vanilla1.hpp"

VanillaOption::VanillaOption(PayOff &ThePayOff, double Expiry)
: ThePayOff(ThePayOff), Expiry(Expiry){
    
}

double VanillaOption::GetExpiry() const{
    
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const{
    return ThePayOff(Spot);
}

