//---------------------------------------------------------------//
//  Problem Statement: Find first positive root of Sine function
//                     to six digits.
//  Name: Thomas Bement
//  SN: XXXXXXX
//  UBC Oakanagan
//  Copyright 2018, All rights reserved
//---------------------------------------------------------------//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

long double ldubFunc(long double x){
    return sin(x);
}

int main()
{
    bool bAnswer=false;
    long double ldubEpsilon = 0.000008;
    long double ldubLower = 4.0;
    long double ldubUpper = 2.0;
    long double ldubTest = (ldubLower+ldubUpper)/2.0;

    cout<<"Test Points: \n"<<ldubTest<<endl;

    while (bAnswer==false) {
        if (fabs(ldubFunc(ldubTest)) <= ldubEpsilon) {
            cout<<"Zero is near: "<<ldubTest<<endl;
            bAnswer=true;
        }
        else if (ldubFunc(ldubTest) > 0) {
            if (ldubFunc(ldubUpper) > 0) {
                // f(test) is + and f(upper) is also + so theres no zero
                // in that range and upper is updated to test
                //
                ldubUpper = ldubTest;
                ldubTest = (ldubLower+ldubUpper)/2.0;
                cout<<ldubTest<<endl;
            }
            else {
                // f(test) is + and f(upper) is - so there is a zero in
                // that range so lower is updated to test
                //
                ldubLower = ldubTest;
                ldubTest = (ldubLower+ldubUpper)/2.0;
                cout<<ldubTest<<endl;
            }
        }
        else if (ldubFunc(ldubTest) < 0) {
            if (ldubFunc(ldubUpper) < 0) {
                // f(test) is - and f(upper) is also - so theres no zero
                // in that range and upper is updated to test
                ldubUpper = ldubTest;
                ldubTest = (ldubLower+ldubUpper)/2.0;
                cout<<ldubTest<<endl;
            }
            else {
                // f(test) is - and f(upper) is + so there is a zero in
                // that range so lower is updated to test
                ldubLower = ldubTest;
                ldubTest = (ldubLower+ldubUpper)/2.0;
                cout<<ldubTest<<endl;
            }
        }
    }
    return 0;
}
