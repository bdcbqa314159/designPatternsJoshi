#ifndef EXOTICBSENGINE_H
#define EXOTICBSENGINE_H

#include "./exoticEngine.hpp"
#include "./random2.hpp"

class ExoticBSEngine : public ExoticEngine {
    
public:
    ExoticBSEngine(const Wrapper<PathDependent> &TheProduct_, const Parameters &R_,  const Parameters &D_, const Parameters &Vol_, const Wrapper<RandomBase> &TheGenerator_, double Spot_);
    virtual void GetOnePath(MJArray &SpotValues);
    virtual ~ExoticBSEngine(){};
    
private:
    Wrapper<RandomBase> TheGenerator;
    MJArray Drifts;
    MJArray StandardDeviations;
    double LogSpot;
    unsigned long NumberOfTimes;
    MJArray Variates;
};
#endif /* ExoticBSEngine_h */
