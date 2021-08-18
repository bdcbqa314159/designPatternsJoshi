#ifndef BLACKSCHOLESFORMULAS_H
#define BLACKSCHOLESFORMULAS_H

#include "normals.hpp"
#include <cmath>

double BlackScholesCall(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesPut(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesDigitalCall(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesDigitalPut(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesCallVega(double Spot, double Strike, double r, double d, double Vol, double Expiry);

#endif 
