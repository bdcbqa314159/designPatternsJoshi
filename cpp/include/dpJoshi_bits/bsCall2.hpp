#ifndef BSCALL2_H
#define BSCALL2_H

class BSCall2 {
    
public:
    BSCall2(double r_, double d_, double T_, double Spot_, double Strike_);
    double Price(double Vol) const;
    double Vega(double Vol) const;
    
private:
    double r;
    double d;
    double T;
    double Spot;
    double Strike;
    
};
#endif 
