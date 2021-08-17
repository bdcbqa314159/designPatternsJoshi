#ifndef PATHDEPENDENTASIAN_H
#define PATHDEPENDENTASIAN_H

#include "./pathDependent.hpp"
#include "./payoffBridge.hpp"

class PathDependentAsian : public PathDependent {
    
public:
    PathDependentAsian(const MJArray &LookAtTimes_, double DeliveryTimes_, const PayOffBridge &ThePayOff_);
    virtual unsigned long MaxNumberOfCashFlows() const;
    virtual MJArray PossibleCashFlowTimes() const;
    virtual unsigned long CashFlows(const MJArray &SpotValues, std::vector<CashFlow> &GeneratedFlows) const;
    virtual ~PathDependentAsian(){}
//    virtual PathDependent *clone() const;
    virtual std::shared_ptr<PathDependent> clone() const;
    
private:
    double DeliveryTime;
    PayOffBridge ThePayOff;
    unsigned long NumberOfTimes;
};

#endif /* PathDependentAsian_h */
