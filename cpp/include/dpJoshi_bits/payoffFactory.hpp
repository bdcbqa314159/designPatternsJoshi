#ifndef PAYOFFFACTORY_H
#define PAYOFFFACTORY_H
#include "./payoff3.hpp"

#include <map>
#include <string>

//class PayOffFactory {
//
//public:
//    typedef PayOff3* (*CreatePayOffFunction(double));
//    static PayOffFactory& Instance();
//    void RegisterPayOff(std::string, CreatePayOffFunction);
//    PayOff3* CreatePayOff(std::string PayOffId, double Strike);
//    ~PayOffFactory(){};
//
//private:
//    std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
//    PayOffFactory(){}
//    PayOffFactory(const PayOffFactory &){}
//    PayOffFactory& operator=(const PayOffFactory &){return *this;}
//};

#endif /* PayOffFactory_h */

