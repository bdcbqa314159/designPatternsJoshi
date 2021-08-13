#ifndef CONVERGENCETABLE_H
#define CONVERGENCETABLE_H

#include "./mcStatistics.hpp"
#include "./wrapper.hpp"

class ConvergenceTable : public StatisticsMC {
    
public:
    ConvergenceTable(const Wrapper<StatisticsMC> &Inner_);
    
//    virtual StatisticsMC *clone() const;
    virtual std::shared_ptr<StatisticsMC> clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;

private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double>> ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
    
};


#endif
