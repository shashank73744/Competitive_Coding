//
//  main.cpp
//  Journey
//
//  Created by Shashank Saurabh on 1/12/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
double fcn(double x){
    return x*x-1;
}
double fcn2(double x){
    return x*x*x*x*x-exp(x)-2;
}
double root_find(double f(double),double a,double b,double eps,double *root){
    if (b-a<eps) {
        *root=b+a/2;
        return f(*root);
    } else {
        if (f(a)*f((b+a)/2)<=0) {
           return root_find(f, a, (b+a)/2, eps, root);
        } else {
            return root_find(f,(b+a)/2, b, eps, root);
        }
    }
}
int main(int argc, const char * argv[]) {
    double x;
    cout<<"Root Finder"<<endl;
    root_find(fcn, 0.0, 4.0, 0.0001, &x);
    cout<<"Root is at "<<x<<" with residual "<<fcn(x)<<endl;
    root_find(fcn2, 0.0, 14.0, 0.0001, &x);
    cout<<"Root is at "<<x<<" with residual "<<fcn2(x)<<endl;
    return 0;
    
}