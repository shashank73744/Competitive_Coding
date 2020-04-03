//
//  main.cpp
//  Saving The Universe Again
//
//  Created by Shashank Saurabh on 4/7/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

const int INF = 100000009;

int swaps(int *p,long long reduction,int n){
    
    if(reduction<=0)return 0;
    else if(n==0) return -1*INF;
    else if(p[n]==0)return swaps(p,reduction,n-1);
    else if(p[n]*pow((double)2, (double)(n-1))<reduction){
        reduction -=p[n]*(long long)pow(2, (n-1));
        p[n-1]+=p[n];
        return p[n] + swaps(p,reduction,n-1);
    }
    else{
        return ceil(reduction/pow((double)2, (double)(n-1)));
    }
}


void initialize(int*p,int &pc,long long &attack,long long &reduction, long long &C,int &counter){
    for (int i=0; i<30; i++) {
        p[i] = 0;
    }
    pc=0;C=1;attack=0;reduction=0;counter=0;
    
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Saving The Universe Again/Saving The Universe Again/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Saving The Universe Again/Saving The Universe Again/output.txt", "w", stdout);
    long long attack =0, reduction =0,D,C=1;
    int T,pc=0,p[30],counter=0;
    char str[31];
    cin>>T;
    for(int i=1;i<=T;i++){
        initialize(p,pc,attack,reduction,C,counter);
        cin>>D;
        cin>>str;
        while (str[counter] !='\0') {
            if(str[counter] == 'C'){++pc;C*=2;}
            else{++p[pc],attack+=C;}
            ++counter;
        }
        reduction = attack -D;
        if(swaps(p,reduction,29)>=0)
        cout<<"Case #"<<i<<": "<<swaps(p,reduction,29)<<endl;
        else
        cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
