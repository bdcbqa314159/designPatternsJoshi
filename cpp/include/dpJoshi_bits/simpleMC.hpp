#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include "./random1.hpp"
#include "./payoff1.hpp"
#include "./payoff2.hpp"
#include "./payoff3.hpp"
#include "./vanilla1.hpp"
#include "./vanilla2.hpp"
#include "./vanilla3.hpp"
#include "./parameters.hpp"
#include "./mcStatistics.hpp"
#include "./random2.hpp"
#include "./antithetic.hpp"

#include <cmath>

double SimpleMonteCarlo1(double Expiry,double Strike,double Spot,double Vol,double r,unsigned long NumberOfPaths);

double SimpleMonteCarlo2(const PayOff1 &thePayOff, double Expiry, double spot, double Vol, double r, unsigned long NumberOfPaths);

double SimpleMonteCarlo2(const PayOff &thePayOff,double Expiry, double spot, double Vol, double r, unsigned long NumberOfPaths);

double SimpleMonteCarlo3(const VanillaOption &TheOption,double Spot, double Vol, double r, unsigned long NumberOfPaths);

double SimpleMonteCarlo4(const VanillaOption2 &TheOption, double Spot, double Vol, double r, unsigned long NumberOfPaths);

double SimpleMonteCarlo5(const VanillaOption3 &TheOption, double Spot, double Vol, double r, unsigned long NumberOfPaths);

double SimpleMonteCarlo6(const VanillaOption3 &TheOption, double Spot, const Parameters &Vol, const Parameters &r, unsigned long NumberOfPaths);

void SimpleMonteCarlo7(const VanillaOption3 &TheOption, double Spot, const Parameters &Vol, const Parameters &r, unsigned long NumberOfPaths, StatisticsMC &gatherer);

void SimpleMonteCarlo8(const VanillaOption3 &TheOption, double Spot, const Parameters &Vol, const Parameters &r, unsigned long NumberOfPaths, StatisticsMC &gatherer, RandomBase &generator);

#endif
