#ifndef PAYOFFCONSTRUCTIBLE_H
#define PAYOFFCONSTRUCTIBLE_H


 #include <iostream>
 #include "./payoff3.hpp"
 #include "./payoffFactory.hpp"
 
//template <class T>
//class PayOffHelper{
// 
//public:
//    PayOffHelper(std::string);
//    static PayOff3 *Create(double);
//};
// 
//template <class T>
//PayOff3* PayOffHelper<T>::Create(double Strike){
// 
//    return new T(Strike);
//}
// 
//template <class T>
//PayOffHelper<T>::PayOffHelper(std::string id){
//    PayOffFactory &thePayOffFactory = PayOffFactory::Instance();
//    thePayOffFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
//}
 

#endif /* PayOffConstructible_h */

