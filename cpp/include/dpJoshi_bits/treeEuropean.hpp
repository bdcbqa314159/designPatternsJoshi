#ifndef TREEEUROPEAN_H
#define TREEEUROPEAN_H

#include "./treeProducts.hpp"
#include "./payoffBridge.hpp"


class TreeEuropean : public TreeProduct {
    
public:
    TreeEuropean(double FinalTime, const PayOffBridge &ThePayOff_);
//    virtual TreeProduct *clone() const;
    virtual std::shared_ptr<TreeProduct> clone() const;
    virtual double FinalPayOff(double Spot) const;
    virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
    virtual ~TreeEuropean(){}
    
private:
    PayOffBridge ThePayOff;
};


#endif /* TreeEuropean_h */

