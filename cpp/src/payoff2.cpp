#include "../include/dpJoshi_bits/payoff2.hpp"

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_){
    
}

double PayOffCall::operator()(double Spot) const {
    
    return std::max(Spot-Strike, 0.0);

}

double PayOffPut::operator()(double Spot) const {
    
    return std::max(Strike-Spot, 0.0);
    
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_){
    
}

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_, double UpperLevel_)
: LowerLevel(LowerLevel_), UpperLevel(UpperLevel_){
    
}

double PayOffDoubleDigital::operator()(double Spot) const {
    
    if (Spot <= LowerLevel){
        return 0;
    }
    if (Spot >= UpperLevel){
        return 0;
    }
    
    return 1;
}
