#include "../include/dpJoshi_bits/treeAmerican.hpp"

TreeAmerican::TreeAmerican(double FinalTime, const PayOffBridge &ThePayOff_)
: TreeProduct(FinalTime), ThePayOff(ThePayOff_){
    
}

std::shared_ptr<TreeProduct> TreeAmerican::clone() const {
    
    return std::shared_ptr<TreeProduct>(new TreeAmerican(*this));
}

double TreeAmerican::FinalPayOff(double Spot) const {
    
    return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const {
    
    return std::max(ThePayOff(Spot), DiscountedFutureValue);
}

