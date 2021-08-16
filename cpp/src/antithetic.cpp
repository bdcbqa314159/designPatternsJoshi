#include "../include/dpJoshi_bits/antithetic.hpp"

Antithetic::Antithetic(const Wrapper<RandomBase> &innerGenerator)
: RandomBase(*innerGenerator), InnerGenerator(innerGenerator){
    
    InnerGenerator->Reset();
    OddEven = true;
    NextVariates.resize(GetDimensionality());
}

std::shared_ptr<RandomBase> Antithetic::clone() const{
    
    return std::shared_ptr<RandomBase>(new Antithetic(*this));
}

void Antithetic::GetUniforms(MJArray &variates){
    
    if (OddEven){
        InnerGenerator->GetUniforms(variates);
        
        for (unsigned long i{}; i<GetDimensionality();++i)
            NextVariates[i] = 1.0-variates[i];
        OddEven = false;
    }
    
    else{
        variates = NextVariates;
        OddEven = true;
    }
}

void Antithetic::SetSeed(unsigned long Seed){
    InnerGenerator->SetSeed(Seed);
    OddEven =true;
}

void Antithetic::Skip(unsigned long numberOfPaths){
    
    if (numberOfPaths==0)
        return;
    
    if (OddEven){
        OddEven = false;
        numberOfPaths--;
    }
    
    InnerGenerator->Skip(numberOfPaths/2);
    
    if (numberOfPaths%2){
        MJArray tmp(GetDimensionality());
        GetUniforms(tmp);
    }
}

void Antithetic::ResetDimensionality(unsigned long NewDimensionality){
    
    RandomBase::ResetDimensionality(NewDimensionality);
    NextVariates.resize(NewDimensionality);
    InnerGenerator->ResetDimensionality(NewDimensionality);
}

void Antithetic::Reset(){
    InnerGenerator->Reset();
    OddEven = true;
}

