#include "./bsCall2.hpp"
#include "./blackScholesFormulas.hpp"

BSCall2::BSCall2(double r_, double d_, double T_, double Spot_, double Strike_)
: r(r_), d(d_), T(T_), Spot(Spot_), Strike(Strike_){
    
}

double BSCall2::Price(double Vol) const {
    return BlackScholesCall(Spot, Strike, r, d, Vol, T);
}

double BSCall2::Vega(double Vol) const {
    return BlackScholesCallVega(Spot, Strike, r, d, Vol, T);
}
