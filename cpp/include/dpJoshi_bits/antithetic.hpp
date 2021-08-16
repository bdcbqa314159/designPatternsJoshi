#ifndef ANTITHETIC_H
#define ANTITHETIC_H


#include "./random2.hpp"
#include "./wrapper.hpp"

class Antithetic:public RandomBase {
    
public:
    Antithetic(const Wrapper<RandomBase> &innerGenerator);
//    virtual RandomBase *clone() const;
    virtual std::shared_ptr<RandomBase> clone() const;
    virtual void GetUniforms(MJArray &variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    virtual void Reset();
    
private:
    Wrapper<RandomBase> InnerGenerator;
    
    bool OddEven;
    
    MJArray NextVariates;
};

#endif
