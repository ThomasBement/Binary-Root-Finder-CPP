//-------------------------------------------------------//
//  Problem Statement:
//  Name: Thomas Bement
//  SN: 24099822
//  UBC Oakanagan
//  Copyright 2018, All rights reserved
//-------------------------------------------------------//
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
long double ldubFunc(long double x){
    return sin(x);
}

int main(){
bool bAnswer=false;
long double ldubLower=4;
long double ldubUpper=2;
long double ldubTest = (ldubLower+ldubUpper)/2;
cout<<"Test Points: \n"<<ldubTest<<endl;
while (bAnswer==false) {
    if (sin(ldubTest) == 0) {
        cout<<"Zero is at: "<<ldubTest<<endl;
        bAnswer=true;
    }
    else if (ldubFunc(ldubTest) > 0) {
        if (ldubFunc(ldubUpper) > 0) {
            // f(test) is + and f(upper) is also + so theres no zero in that range and upper is updated to test
            ldubUpper = ldubTest;
            ldubTest = (ldubLower+ldubUpper)/2;
            cout<<ldubTest<<endl;
        }
        else {
            //f(test) is + and f(upper) is - so there is a zero in that range so lower is updated to test
            ldubLower = ldubTest;
            ldubTest = (ldubLower+ldubUpper)/2;
            cout<<ldubTest<<endl;
        }
    }
    else if (ldubFunc(ldubTest) < 0) {
        if (ldubFunc(ldubUpper) < 0) {
            // f(test) is - and f(upper) is also - so theres no zero in that range and upper is updated to test
            ldubUpper = ldubTest;
            ldubTest = (ldubLower+ldubUpper)/2;
            cout<<ldubTest<<endl;
        }
        else {
            //f(test) is - and f(upper) is + so there is a zero in that range so lower is updated to test
            ldubLower = ldubTest;
            ldubTest = (ldubLower+ldubUpper)/2;
            cout<<ldubTest<<endl;
        }
    }
}
    return 0;
}
