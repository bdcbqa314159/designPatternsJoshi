#include "../include/dpJoshi_bits/payoffForward.hpp"

double PayOffForward::operator()(double Spot) const{
    return Spot-Strike;
}

PayOffForward::PayOffForward(double Strike_)
: Strike(Strike_){
    
}

std::shared_ptr<PayOff3> PayOffForward::clone() const {
    return std::shared_ptr<PayOff3>(new PayOffForward(*this));
}


