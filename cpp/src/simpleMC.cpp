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

double SimpleMonteCarlo6(const VanillaOption3 &TheOption, double Spot, const Parameters &Vol, const Parameters &r, unsigned long NumberOfPaths){
                        

    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r.Integral(0, Expiry)+itoCorrection);
    double thisSpot;
    double runningSum=0;
    
    for (unsigned long i{}; i<NumberOfPaths; ++i){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayoff;
    }
    
    double mean = runningSum/NumberOfPaths;
    mean *= exp(-r.Integral(0, Expiry));
    return mean;
}


void SimpleMonteCarlo7(const VanillaOption3 &TheOption, double Spot, const Parameters &Vol, const Parameters &r, unsigned long NumberOfPaths, StatisticsMC &gatherer){
                        

    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r.Integral(0, Expiry)+itoCorrection);
    double thisSpot;
    double discounting = exp(-r.Integral(0, Expiry));
    
    for (unsigned long i{}; i<NumberOfPaths; ++i){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayoff*discounting);
    }
    
    return;
    
}

void SimpleMonteCarlo8(const VanillaOption3 &TheOption, double Spot, const Parameters &Vol, const Parameters &r, unsigned long NumberOfPaths, StatisticsMC &gatherer, RandomBase &generator){
                        
    generator.ResetDimensionality(1);
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r.Integral(0, Expiry)+itoCorrection);
    double thisSpot;
    double discounting = exp(-r.Integral(0, Expiry));
    MJArray VariateArray(1);
    
    for (unsigned long i{}; i<NumberOfPaths; ++i){
        generator.GetGaussians(VariateArray);
        thisSpot = movedSpot*exp(rootVariance*VariateArray[0]);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayoff*discounting);
    }
    
    return;
    
}
