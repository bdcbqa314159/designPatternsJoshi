#include <dpJoshi>
#include <iostream>

int testingSimpleMC(){
    
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



int main() {
    
    testingSimpleMC();
    
    
    return 0;
}
