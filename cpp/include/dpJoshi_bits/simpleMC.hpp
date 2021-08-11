#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include "./random1.hpp"
#include "./payoff1.hpp"
#include "./payoff2.hpp"
#include "./vanilla1.hpp"
#include <cmath>

double SimpleMonteCarlo1(double Expiry,double Strike,double Spot,double Vol,double r,unsigned long NumberOfPaths);

double SimpleMonteCarlo2(const PayOff1 &thePayOff, double Expiry, double spot, double Vol, double r, unsigned long NumberOfPaths);

double SimpleMonteCarlo2(const PayOff &thePayOff,double Expiry, double spot, double Vol, double r, unsigned long NumberOfPaths);

double SimpleMonteCarlo3(const VanillaOption &TheOption,double Spot, double Vol, double r, unsigned long NumberOfPaths);


#endif
