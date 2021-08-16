#ifndef RANDOM2_H
#define RANDOM2_H

#include <memory>
#include "./arrays.hpp"

class RandomBase {
    
public:
    RandomBase(unsigned long Dimensionality);
    inline unsigned long GetDimensionality() const;
    
//    virtual RandomBase *clone() const=0;
    virtual std::shared_ptr<RandomBase> clone() const=0;
    virtual void GetUniforms(MJArray & varitates)=0;
    virtual void Skip(unsigned long numberOfPaths)=0;
    virtual void SetSeed(unsigned long Seed)=0;
    virtual void Reset()=0;
    
    virtual void GetGaussians(MJArray &variates);
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    virtual ~RandomBase();
private:
    unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality() const{
    
    return Dimensionality;
}

#endif /* Random2_h */
