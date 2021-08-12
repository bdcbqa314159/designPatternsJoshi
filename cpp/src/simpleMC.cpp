#include "../include/dpJoshi_bits/simpleMC.hpp"


double SimpleMonteCarlo1(double Expiry, double Strike, double Spot, double Vol,double r, unsigned long NumberOfPaths){
                            
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r*Expiry + itoCorrection);
    double thisSpot;
    double runningSum=0;
    
    for (unsigned long i=0; i<NumberOfPaths; ++i){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = thisSpot-Strike;
        thisPayoff = thisPayoff>0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }
    
    double mean = runningSum/NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

double SimpleMonteCarlo2(const PayOff1 &thePayOff, double Expiry, double Spot, double Vol, double r, unsigned long NumberOfPaths){
                        

    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r*Expiry + itoCorrection);
    double thisSpot;
    double runningSum=0;
    
    for (unsigned long i = 0; i<NumberOfPaths; ++i){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = thePayOff(thisSpot);
        runningSum += thisPayoff;
    }
    
    double mean = runningSum/NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

double SimpleMonteCarlo2(const PayOff &thePayOff, double Expiry, double Spot, double Vol, double r, unsigned long NumberOfPaths){
                        

    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r*Expiry+itoCorrection);
    double thisSpot;
    double runningSum=0;
    
    for (unsigned long i{}; i<NumberOfPaths; ++i){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = thePayOff(thisSpot);
        runningSum += thisPayoff;
    }
    
    double mean = runningSum/NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

double SimpleMonteCarlo3(const VanillaOption &TheOption, double Spot, double Vol, double r, unsigned long NumberOfPaths){
                        

    double Expiry = TheOption.GetExpiry();
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r*Expiry+itoCorrection);
    double thisSpot;
    double runningSum=0;
    
    for (unsigned long i{}; i<NumberOfPaths; ++i){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayoff;
    }
    
    double mean = runningSum/NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

double SimpleMonteCarlo4(const VanillaOption2 &TheOption, double Spot, double Vol, double r, unsigned long NumberOfPaths){
                        

    double Expiry = TheOption.GetExpiry();
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r*Expiry+itoCorrection);
    double thisSpot;
    double runningSum=0;
    
    for (unsigned long i{}; i<NumberOfPaths; ++i){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayoff;
    }
    
    double mean = runningSum/NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

double SimpleMonteCarlo5(const VanillaOption3 &TheOption, double Spot, double Vol, double r, unsigned long NumberOfPaths){
                        

    double Expiry = TheOption.GetExpiry();
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r*Expiry+itoCorrection);
    double thisSpot;
    double runningSum=0;
    
    for (unsigned long i{}; i<NumberOfPaths; ++i){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayoff;
    }
    
    double mean = runningSum/NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}
