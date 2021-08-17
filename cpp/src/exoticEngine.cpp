#include "../include/dpJoshi_bits/exoticEngine.hpp"
#include <cmath>

ExoticEngine::ExoticEngine(const Wrapper<PathDependent> &TheProduct_, const Parameters &r_)
: TheProduct(TheProduct_), r(r_), Discounts(TheProduct_->PossibleCashFlowTimes()){
    
    for (unsigned long i{}; i<Discounts.size(); ++i)
        Discounts[i] = exp(-r.Integral(0.0, Discounts[i]));
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
}

void ExoticEngine::DoSimulation(StatisticsMC & TheGatherer, unsigned long NumberOfPaths){
    
    MJArray SpotValues(TheProduct->GetLookAtTimes().size());
    
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
    
    double thisValue;
    
    for (unsigned long i{}; i<NumberOfPaths; ++i){
        
        GetOnePath(SpotValues);
        thisValue = DoOnePath(SpotValues);
        TheGatherer.DumpOneResult(thisValue);
    }
    
    return;
}

double ExoticEngine::DoOnePath(const MJArray &SpotValues) const {
    
    unsigned long NumberOfFlows = TheProduct->CashFlows(SpotValues, TheseCashFlows);
    
    double Value=0.0;
    
    for (unsigned long i{}; i<NumberOfFlows;++i){
        Value += TheseCashFlows[i].Amount*Discounts[TheseCashFlows[i].TimeIndex];
    }
    
    return Value;
}

