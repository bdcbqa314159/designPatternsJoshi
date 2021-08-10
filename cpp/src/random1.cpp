#include "../include/dpJoshi_bits/random1.hpp"

double GetOneGaussianBySummation(){
    
    double result=0;
    for (unsigned long j{}; j<12; ++j)
        result += rand()/static_cast<double>(RAND_MAX);
        
    result -= 6.0;
        
    return result;
}

double GetOneGaussianByBoxMuller(){
    
    double result{}, x{}, y{}, sizeSquared{};
    
    do{
        x = 2.0*rand()/static_cast<double>(RAND_MAX)-1;
        y = 2.0*rand()/static_cast<double>(RAND_MAX)-1;
        
        sizeSquared = x*x + y*y;
        
    }while(sizeSquared>=1.);
    
    result = x*sqrt(-2*log(sizeSquared)/sizeSquared);
    
    return result;
}
