#include "../include/dpJoshi_bits/treeEuropean.hpp"

TreeEuropean::TreeEuropean(double FinalTime, const PayOffBridge &ThePayOff_)
: TreeProduct(FinalTime), ThePayOff(ThePayOff_){
    
}

std::shared_ptr<TreeProduct> TreeEuropean::clone() const {
    
    return std::shared_ptr<TreeProduct>(new TreeEuropean(*this));
}

double TreeEuropean::FinalPayOff(double Spot) const {
    
    return ThePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const {
    
    return DiscountedFutureValue;
}

