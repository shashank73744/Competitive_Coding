//
//  main.cpp
//  testing
//
//  Created by Shashank Saurabh on 2/8/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[]) {
    long long unsigned sum=1,m,n,x,s;
    cin>>n>>m;
    long long unsigned* f=new long long unsigned[10000001];
    for (long long unsigned i=1; i<m; i++) {
        sum=(sum*i)%m;
        f[i]=sum;
            }
    f[0]=1;
    sum=0;
    for (long long unsigned i=0; i<n; i++) {
        cin>>x;
        s=x*(x+1);
        s=s/2;
        s=s%m;
        s=s*x;
        s=s%m;
        if (x+1>=m) {
            s=s+m-1;
            s=s%m;
        }
        if (x+1<m) {
            s=s+f[x+1]-1+m;
            s=s%m;
        }
        sum=sum+s;
        sum=sum%m;
    }
    cout<<sum;
    return 0;
}