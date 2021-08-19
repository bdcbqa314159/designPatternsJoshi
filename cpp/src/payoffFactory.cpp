#include "../include/dpJoshi_bits/payoffFactory.hpp"
#include <iostream>

//void PayOffFactory::RegisterPayOff(std::string PayOffId,
//                                   CreatePayOffFunction CreatorFunction){
//    this->TheCreatorFunctions.insert(std::pair<std::string, CreatePayOffFunction>(PayOffId, CreatorFunction));
//}

//PayOff3* PayOffFactory::CreatePayOff(std::string PayOffId, double Strike){
//    
//    std::map<std::string, CreatePayOffFunction>::const_iterator i = TheCreatorFunctions.find(PayOffId);
//    
//    if (i==TheCreatorFunctions.end()){
//        std::cout<<PayOffId<<"is an unknown payoff" << std::endl;
//        return NULL;
//    }
//    
//    return (i->second)(Strike);
//}
//
//
//PayOffFactory &PayOffFactory::Instance(){
//    
//    static PayOffFactory theFactory;
//    return theFactory;
//}
