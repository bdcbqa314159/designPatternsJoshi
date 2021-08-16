#include "../include/dpJoshi_bits/random2.hpp"
#include "../include/dpJoshi_bits/normals.hpp"
#include <cstdlib>

void RandomBase::GetGaussians(MJArray &variates){
    
    GetUniforms(variates);
    
    for(unsigned long i{}; i<Dimensionality; ++i){
        double x = variates[i];
        variates[i] = InverseCumulativeNormal(x);
    }
}

void RandomBase::ResetDimensionality(unsigned long NewDimensionality){
    
    Dimensionality = NewDimensionality;
}

RandomBase::RandomBase(unsigned long Dimensionality_)
: Dimensionality(Dimensionality_){
    
}

RandomBase::~RandomBase(){
    
}
