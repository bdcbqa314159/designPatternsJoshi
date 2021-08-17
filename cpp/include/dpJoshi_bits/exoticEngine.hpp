#ifndef EXOTICENGINE_H
#define EXOTICENGINE_H

#include "./wrapper.hpp"
#include "./parameters.hpp"
#include "./pathDependent.hpp"
#include "./mcStatistics.hpp"
#include <vector>

class ExoticEngine {
    
public:
    ExoticEngine(const Wrapper<PathDependent> &TheProduct_, const Parameters &r_);
    virtual void GetOnePath(MJArray &SpotValues)=0;
    void DoSimulation(StatisticsMC &TheGatherer, unsigned long NumbersOfPaths);
    virtual ~ExoticEngine(){};
    double DoOnePath(const MJArray &SpotValues) const;

private:
    Wrapper<PathDependent> TheProduct;
    Parameters r;
    MJArray Discounts;
    mutable std::vector<CashFlow> TheseCashFlows;
};
#endif /* ExoticEngine_h */
