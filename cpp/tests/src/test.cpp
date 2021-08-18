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
    
    PayOff1 callPayOff(Strike, PayOff1::call);
    PayOff1 putPayOff(Strike, PayOff1::put);
    
    
    double resultCall = SimpleMonteCarlo2(callPayOff,Expiry, Spot, Vol, r, NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayOff,Expiry, Spot, Vol, r, NumberOfPaths);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    
    std::cout<<"Call price with simple MC : "<<resultCall<<std::endl;
    std::cout<<"Put price with simple MC : "<<resultPut<<std::endl;

    
    return 0;
}

int testingSimpleMC2_otherPayOff(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);
    
    double resultCall = SimpleMonteCarlo2(callPayOff,Expiry, Spot, Vol, r, NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayOff,Expiry, Spot, Vol, r, NumberOfPaths);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    
    std::cout<<"Call price with simple MC : "<<resultCall<<std::endl;
    std::cout<<"Put price with simple MC : "<<resultPut<<std::endl;
    
    return 0;
}


int testingSimpleMC2_otherPayOff_pointer(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    unsigned long optionType;
    
    std::cout<<"Enter 0 for call, otherwise put ";
    std::cin>>optionType;
    
    PayOff* thePayOffPtr;
    
    if (optionType == 0) thePayOffPtr = new PayOffCall(Strike);
    else thePayOffPtr = new PayOffPut(Strike);
    
    
    double result = SimpleMonteCarlo2(*thePayOffPtr, Expiry, Spot, Vol, r, NumberOfPaths);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    
    if (optionType == 0)
        std::cout<<"Call price with simple MC : "<<result<<std::endl;
    
    else
        std::cout<<"Put price with simple MC : "<<result<<std::endl;
    
    delete thePayOffPtr;

    
    return 0;
}

int testingSimpleMC2_doubleDigital(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    double LowerLevel = 100;
    double UpperLevel = 120;
   
    
    PayOffDoubleDigital payOffDD(LowerLevel,UpperLevel);
    
    
    double result = SimpleMonteCarlo2(payOffDD, Expiry, Spot, Vol, r, NumberOfPaths);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    //From another book - price has to be around "Options Price:   0.32009"
    
    std::cout<<"Double Digital price with simple MC : "<<result<<std::endl;
    
    return 0;
}

int testingSimpleMC3_doubleDigital(){
    
    
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    double LowerLevel = 100;
    double UpperLevel = 120;
   
    
    PayOffDoubleDigital payOffDD(LowerLevel,UpperLevel);
    VanillaOption theOption(payOffDD, Expiry);
    
    
    double result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    //From another book - price has to be around "Options Price:   0.32009"
    
    std::cout<<"Double Digital price with simple MC : "<<result<<std::endl;

    
    return 0;
}

int testtingSimpleMC4(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    double LowerLevel = 100;
    double UpperLevel = 120;
   
    
    PayOffDoubleDigital3 payOffDD(LowerLevel,UpperLevel);
    VanillaOption2 theOption(payOffDD, Expiry);
    
    
    double result = SimpleMonteCarlo4(theOption, Spot, Vol, r, NumberOfPaths);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    //From another book - price has to be around "Options Price:   0.32009"
    
    std::cout<<"Double Digital price with simple MC : "<<result<<std::endl;

    return 0;
}

int testtingSimpleMC5(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    double LowerLevel = 100;
    double UpperLevel = 120;
   
    
    PayOffDoubleDigital3 payOffDD(LowerLevel,UpperLevel);
    VanillaOption3 theOption(payOffDD, Expiry);
    
    
    double result = SimpleMonteCarlo5(theOption, Spot, Vol, r, NumberOfPaths);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    //From another book - price has to be around "Options Price:   0.32009"
    
    std::cout<<"Double Digital price with simple MC : "<<result<<std::endl;

    return 0;
}

int testingSimpleMC6(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    double LowerLevel = 100;
    double UpperLevel = 120;
   
    
    PayOffDoubleDigital3 payOffDD(LowerLevel,UpperLevel);
    VanillaOption3 theOption(payOffDD, Expiry);
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    
    
    double result = SimpleMonteCarlo6(theOption, Spot, VolParam, rParam, NumberOfPaths);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    //From another book - price has to be around "Options Price:   0.32009"
    
    std::cout<<"Double Digital price with simple MC : "<<result<<std::endl;

    return 0;
    
}


int testingSimpleMC7(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    double LowerLevel = 100;
    double UpperLevel = 120;
   
    
    PayOffDoubleDigital3 payOffDD(LowerLevel,UpperLevel);
    VanillaOption3 theOption(payOffDD, Expiry);
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    
    StatisticsMean gatherer;
    
    
    SimpleMonteCarlo7(theOption, Spot, VolParam, rParam, NumberOfPaths,gatherer);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    //From another book - price has to be around "Options Price:   0.32009"
    
    std::vector<std::vector<double> > results = gatherer.GetResultsSoFar();
    
    std::cout<<"For double Digital price the results are : "<<std::endl;
    
    for (unsigned long i = 0; i<results.size(); i++){
        for (unsigned long j = 0; j<results.at(i).size(); j++){
            
            std::cout<<results.at(i).at(j)<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
    
}

int testingSimpleMC7_withWrapper(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    double LowerLevel = 100;
    double UpperLevel = 120;
   
    
    PayOffDoubleDigital3 payOffDD(LowerLevel,UpperLevel);
    VanillaOption3 theOption(payOffDD, Expiry);
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    
    SimpleMonteCarlo7(theOption, Spot, VolParam, rParam, NumberOfPaths,gathererTwo);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    //From another book - price has to be around "Options Price:   0.32009"
    
    std::vector<std::vector<double> > results = gathererTwo.GetResultsSoFar();
    
    std::cout<<"For double Digital price the results are : "<<std::endl;
    
    for (unsigned long i = 0; i<results.size(); i++){
        for (unsigned long j = 0; j<results.at(i).size(); j++){
            
            std::cout<<results.at(i).at(j)<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
    
}

int testingSimpleMC8(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    
    unsigned long NumberOfPaths = 100000;
    
    double LowerLevel = 100;
    double UpperLevel = 120;
   
    
    PayOffDoubleDigital3 payOffDD(LowerLevel,UpperLevel);
    VanillaOption3 theOption(payOffDD, Expiry);
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    RandomParkMiller generator(1);
    Antithetic GenTwo(generator);
    
    SimpleMonteCarlo8(theOption, Spot, VolParam, rParam, NumberOfPaths,gathererTwo,GenTwo);

    
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    //From another book - price has to be around "Options Price:   0.32009"
    
    std::vector<std::vector<double> > results = gathererTwo.GetResultsSoFar();
    
    std::cout<<"For double Digital price the results are : "<<std::endl;
    
    for (unsigned long i = 0; i<results.size(); i++){
        for (unsigned long j = 0; j<results.at(i).size(); j++){
            
            std::cout<<results.at(i).at(j)<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
    
}

int testingBSEngine(){
    
    double Expiry = 1.;
    double Strike = 29;
    double Spot = 30;
    double Vol = 0.3;
    double r = 0.08;
    double d = 0;
    
    unsigned long NumberOfPaths = 1000000;
    unsigned long NumberOfDates = 250;
   
//    PayOffCall3 thePayOff(Strike);
    PayOffPut3 thePayOff(Strike);
    MJArray times(NumberOfDates);
    
    for (unsigned long i = 0; i<NumberOfDates; i++){
        times[i] = (i+1.)*Expiry/NumberOfDates;
    }
    
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    
    PathDependentAsian theOption(times, Expiry, thePayOff);
    
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    RandomParkMiller generator(NumberOfDates);
    Antithetic GenTwo(generator);
    
    ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);

    theEngine.DoSimulation(gathererTwo, NumberOfPaths);
    //From another book - price has to be around "Call Price : 10.4506"
    //From another book - price has to be around "Put Price : 5.57352"
    //From another book - price has to be around "Options Price:   0.32009"
    
    std::vector<std::vector<double> > results = gathererTwo.GetResultsSoFar();
    
    std::cout<<"For the Asian Call price the results are : "<<std::endl;
    
    for (unsigned long i = 0; i<results.size(); i++){
        for (unsigned long j = 0; j<results.at(i).size(); j++){
            
            std::cout<<results.at(i).at(j)<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
}

int testingTreePricer(){
    
    double Expiry = 1.;
    double Strike = 100;
    double Spot = 100;
    double Vol = 0.2;
    double r = 0.05;
    double d = 0;
    unsigned long Steps = 1000;

    PayOffCall3 thePayOff(Strike);
    
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    
    TreeEuropean euroOption(Expiry, thePayOff);
//    TreeAmerican amOption(*expiry, thePayOff);
    
    SimpleBinomialTree theTree(Spot, rParam, dParam, Vol, Steps, Expiry);
    
    double euroPrice = theTree.GetThePrice(euroOption);
//    double amPrice = theTree.GetThePrice(amOption);
    
    std::cout<<"euro Price tree : ";
    //From another book - price has to be around "Call Price : 10.4506"
    std::cout<<euroPrice<<std::endl;
    
//    std::cout<<"am Price tree : ";
//    std::cout<<amPrice<<std::endl;
//
    double BSPrice = BlackScholesCall(Spot, Strike, r, d, Vol, Expiry);

    std::cout<<"BS formula euro price : "<<BSPrice<<std::endl;

    PayOffForward forwardPayOff(Strike);
    TreeEuropean forward(Expiry, forwardPayOff);

    double forwardPrice = theTree.GetThePrice(forward);

    std::cout<<"fwd Price tree : ";
    std::cout<<forwardPrice<<std::endl;

    double actualFwdPrice = exp(-r*Expiry)*(Spot*exp((r-d)*Expiry)-Strike);

    std::cout<<"fwd Price : ";
    std::cout<<actualFwdPrice<<std::endl;

    Steps++;
    
    SimpleBinomialTree theNewTree(Spot, rParam, dParam, Vol, Steps, Expiry);
    
    
    double euroNewPrice = theNewTree.GetThePrice(euroOption);
//    double amNewPrice = theNewTree.GetThePrice(amOption);
//
//    std::cout<<"new euro Price tree : ";
//    std::cout<<euroNewPrice<<std::endl;
//
//    std::cout<<"new am Price tree : ";
//    std::cout<<amNewPrice<<std::endl;
//
//
    double forwardNewPrice = theNewTree.GetThePrice(forward);

    std::cout<<"fwd Price tree : ";
    std::cout<<forwardNewPrice<<std::endl;
    
    
    double avEuro = 0.5*(euroPrice+euroNewPrice);
//    double avAm = 0.5*(amPrice+amNewPrice);
    double avFwd = 0.5*(forwardPrice+forwardNewPrice);
//
    std::cout<<"eur av Price: ";
    std::cout<<avEuro<<std::endl;
    
//    std::cout<<"am av Price: ";
//    std::cout<<avAm<<std::endl;
//
    std::cout<<"fwd av Price: ";
    std::cout<<avFwd<<std::endl;

    
    return 0;
}



int main() {
    
//    testingSimpleMC1();
//    testingSimpleMC2();
//    testingSimpleMC2_otherPayOff();
//    testingSimpleMC2_otherPayOff_pointer();
//    testingSimpleMC2_doubleDigital();
//    testingSimpleMC3_doubleDigital();
//    testtingSimpleMC4();
//    testtingSimpleMC5();
//    testingSimpleMC6();
//    testingSimpleMC7();
//    testingSimpleMC7_withWrapper();
//    testingSimpleMC8();
//    testingBSEngine();
    testingTreePricer();
    
    
    return 0;
}
