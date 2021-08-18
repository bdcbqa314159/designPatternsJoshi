#ifndef TREEAMERICAN_H
#define TREEAMERICAN_H

#include "./treeProducts.hpp"
#include "./payoffBridge.hpp"


class TreeAmerican : public TreeProduct {
    
public:
    TreeAmerican(double FinalTime, const PayOffBridge &ThePayOff_);
//    virtual TreeProduct *clone() const;
    virtual std::shared_ptr<TreeProduct> clone() const;
    virtual double FinalPayOff(double Spot) const;
    virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
    virtual ~TreeAmerican(){}
    
private:
    PayOffBridge ThePayOff;
};
#endif /* TreeAmerican_h */
