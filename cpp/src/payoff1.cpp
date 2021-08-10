#include "../include/dpJoshi_bits/payoff1.hpp"

PayOff::PayOff(double Strike, OptionType TheOptionsType)
: Strike(Strike), TheOptionsType(TheOptionsType){
    
}

double PayOff::operator()(double spot) const {
    
    switch (TheOptionsType) {
        case call:
            return std::max(spot-Strike, 0.0);
            break;
        case put:
            return std::max(Strike-spot,0.0);
        default:
            throw std::string{"unknow option type found"};
            break;
    }
}
