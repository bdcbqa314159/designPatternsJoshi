#ifndef PAYOFF1_H
#define PAYOFF1_H
#include <algorithm>
#include <string>

class PayOff {
    
public:
    enum OptionType {call, put};
    PayOff(double Strike, OptionType TheOptionType);
    double operator()(double Spot) const;
private:
    double Strike;
    OptionType TheOptionsType;
};


#endif
