#include "../include/dpJoshi_bits/parkMiller.hpp"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_): Seed(Seed_){
    
    if (Seed==0)
        Seed=1;
}

void ParkMiller::SetSeed(long Seed_){
    Seed=Seed_;
    if (Seed == 0)
        Seed = 1;
}

unsigned long ParkMiller::Max(){
    return m-1;
}

unsigned long ParkMiller::Min(){
    return 1;
}

long ParkMiller::GetOneRandomInteger(){
    long k;
    
    k = Seed/q;
    
    Seed = a*(Seed-k*q)-r*k;
    
    if (Seed<0)
        Seed += m;
    
    return Seed;
}

RandomParkMiller::RandomParkMiller(unsigned long Dimensionality, unsigned long Seed)
: RandomBase(Dimensionality), InnerGenerator(Seed), InitialiSeed(Seed){
    
    Reciprocal = 1/(1.0 +InnerGenerator.Max());
    
}

std::shared_ptr<RandomBase> RandomParkMiller::clone() const{
    return std::shared_ptr<RandomBase>(new RandomParkMiller(*this));
}

void RandomParkMiller::GetUniforms(MJArray &variates){
    
    for (unsigned long j{}; j<GetDimensionality();++j)
    variates[j] =InnerGenerator.GetOneRandomInteger()*Reciprocal;
}

void RandomParkMiller::Skip(unsigned long numberOfPaths){
    MJArray tmp(GetDimensionality());
    for (unsigned long j{}; j<GetDimensionality();++j)
        GetUniforms(tmp);
}

void RandomParkMiller::SetSeed(unsigned long Seed){
    InitialiSeed = Seed;
    InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset(){
    InnerGenerator.SetSeed(InitialiSeed);
}

void RandomParkMiller::ResetDimensionality(unsigned long NewDimensionality){
    RandomBase::ResetDimensionality(NewDimensionality);
    InnerGenerator.SetSeed(InitialiSeed);
}
