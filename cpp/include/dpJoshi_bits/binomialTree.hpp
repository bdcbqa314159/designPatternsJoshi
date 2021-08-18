#ifndef BINOMIALTREE_H
#define BINOMIALTREE_H

#include <vector>
#include <cmath>
#include "./parameters.hpp"
#include "./arrays.hpp"
#include "./treeProducts.hpp"

class SimpleBinomialTree {
    
public:
    SimpleBinomialTree(double Spot_, const Parameters &r_, const Parameters &d_, double Volatility_, unsigned long Steps, double Time);
    double GetThePrice(const TreeProduct &TheProduct);
    
protected:
    void BuildTree();

private:
    double Spot;
    Parameters r;
    Parameters d;
    double Volatility;
    unsigned long Steps;
    double Time;
    bool TreeBuilt;
    
    std::vector<std::vector<std::pair<double, double>>> TheTree;
    MJArray Discounts;
};

#endif /* BinomialTree_h */

