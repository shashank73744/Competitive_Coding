//
//  main.cpp
//  CodeJAMQualification
//
//  Created by Shashank Saurabh on 4/8/17.
//  Copyright (c) 2017 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int debug,len,ans,arr[10003],s[10003];

void div(int n,int st ,int en){
    if(n==0)return;
    if(st>en)return;
    int mid = (st + en)/2;
    arr[mid]=1;
    div( n-1, st , mid-1);
    div( n-1, mid +1 , en);
    
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/j32/j32/input.txt", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/j32/j32/ansSmall.txt","w",stdout);
    int T,N,K,count,nf,pos,gap;
    int n ;
    debug = 1;
    cin>>T;
    //T=1;
    for(int testCase=1;testCase<=T;testCase++){
        cin>>N>>K;
        arr[0]=arr[N+1]=1;
        for(int i=1;i<=N;i++){
            arr[i]=0;
            s[i]=0;
        }
        n = floor(log2(K+1));
        div(n,1,K);
        count =0;
        for(int i=1;i<=N+1;i++){
            if(arr[i]==1){
            ++s[count];
            count = 0;
            }
            else{
                ++count;
            }
            
        }
        nf=K - pow(2,n)+1;
        pos= 0;
        for(int i =1;i<N;i++){
            pos = pos + s[i];
            if(pos >= nf){
                gap = i;
                break;
            }
        }
        cout<<"Case #"<<testCase<<": ";
        cout<<(gap-1)-(gap-1)/2<<" "<<(gap-1)/2<<endl;
    }
    
    
}
