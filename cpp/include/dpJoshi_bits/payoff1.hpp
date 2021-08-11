#ifndef PAYOFF1_H
#define PAYOFF1_H
#include <algorithm>
#include <string>

class PayOff1 {
    
public:
    enum OptionType {call, put};
    PayOff1(double Strike, OptionType TheOptionType);
    double operator()(double Spot) const;
private:
    double Strike;
    OptionType TheOptionsType;
};


#endif
