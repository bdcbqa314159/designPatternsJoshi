#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include "./random1.hpp"
#include <cmath>

double SimpleMonteCarlo1(double Expiry,double Strike,double Spot,double Vol,double r,unsigned long NumberOfPaths);

#endif
