#include "../include/dpJoshi_bits/payoff3.hpp"

PayOffCall3::PayOffCall3(double Strike_) : Strike(Strike_){
    
}

double PayOffCall3::operator()(double Spot) const {
    
    return std::max(Spot-Strike, 0.0);
}

std::shared_ptr<PayOff3> PayOffCall3::clone() const{
    
    return std::shared_ptr<PayOff3>(new PayOffCall3(*this));
}


PayOffPut3::PayOffPut3(double Strike_) : Strike(Strike_){
    
}

double PayOffPut3::operator()(double Spot) const {
    
    return std::max(Strike-Spot, 0.0);
}

std::shared_ptr<PayOff3> PayOffPut3::clone() const {
    
    return std::shared_ptr<PayOff3>(new PayOffPut3(*this));
}


PayOffDoubleDigital3::PayOffDoubleDigital3(double LowerLevel, double UpperLevel)
: LowerLevel(LowerLevel), UpperLevel(UpperLevel){
    
}


double PayOffDoubleDigital3::operator()(double Spot) const {
    
    if (Spot <= LowerLevel){
        return 0;
    }
    if (Spot >= UpperLevel){
        return 0;
    }
    
    return 1;
}

std::shared_ptr<PayOff3> PayOffDoubleDigital3::clone() const {
    
    return std::shared_ptr<PayOff3>(new PayOffDoubleDigital3(*this));
}

