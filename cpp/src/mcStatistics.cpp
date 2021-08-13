#include "../include/dpJoshi_bits/mcStatistics.hpp"

StatisticsMean::StatisticsMean(): RunningSum(0.0), PathsDone(0UL){
    
}

void StatisticsMean::DumpOneResult(double result) {
    
    PathsDone++;
    RunningSum += result;
}

std::vector<std::vector<double>> StatisticsMean::GetResultsSoFar() const {
    
    std::vector<std::vector<double>> Results(1);
    Results[0].resize(1);
    Results[0][0] = RunningSum/PathsDone;
    
    return Results;
}

std::shared_ptr<StatisticsMC> StatisticsMean::clone() const{
    return std::shared_ptr<StatisticsMC>(new StatisticsMean(*this));
}
