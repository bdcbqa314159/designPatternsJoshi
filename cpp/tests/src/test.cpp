#include <dpJoshi>
#include <iostream>

int testingSimpleMC1(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    
    double result = SimpleMonteCarlo1(Expiry, Strike, Spot, Vol, r, NumberOfPaths);

    //From another book - price has to be around "Call Price : 10.4506"
    
    std::cout<<"Call price with simple MC : "<<result<<std::endl;

    
    return 0;
}


int testingSimpleMC2(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);
    
    
    double resultCall = SimpleMonteCarlo2(callPayOff,Expiry, Spot, Vol, r, NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayOff,Expiry, Spot, Vol, r, NumberOfPaths);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    
    std::cout<<"Call price with simple MC : "<<resultCall<<std::endl;
    std::cout<<"Put price with simple MC : "<<resultPut<<std::endl;

    
    return 0;
}



int main() {
    
//    testingSimpleMC1();
    testingSimpleMC2();
    
    
    return 0;
}
