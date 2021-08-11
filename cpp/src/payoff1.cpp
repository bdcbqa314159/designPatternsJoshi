#include "../include/dpJoshi_bits/payoff1.hpp"

PayOff1::PayOff1(double Strike, OptionType TheOptionsType)
: Strike(Strike), TheOptionsType(TheOptionsType){
    
}

double PayOff1::operator()(double spot) const {
    
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
