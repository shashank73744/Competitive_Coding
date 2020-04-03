//
//  main.cpp
//  GoogleCodeJam1
//
//  Created by Shashank Saurabh on 1/21/17.
//  Copyright (c) 2017 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <algorithm>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define CLEAR(array, value) memset(ptr, value, sizeof(array));
#define si(a)     scanf("%d", &a)
#define sl(a)     scanf("%lld", &a)
#define pi(a)     printf("%d", a)
#define pl(a)     printf("%lld", a)
#define pn        printf("\n")
#define SZ(x)  (int)((x).size())
#define YES 0
#define NO 1
#define TIE 2

int debug , arr[250] ,M;
double maximum;

void perm(double *t , int m ,int pos){
    if(m==0){
        if(debug ==1){
            for(int i = 0;i<M;i++)cout<<arr[i];cout<<endl;
        }
        double temp =1;
        for(int i=0;i<M;i++){
            //cout<<temp<<endl;
            if(arr[i]==1)temp*=t[i];
            else temp*=(1-t[i]);
        }
        maximum += temp; ;
        return;
    }
    if(pos>=M)return;
    arr[pos]=1;
    perm( t , m-1 ,pos+1);
    arr[pos]=0;
    perm( t , m ,pos+1);
    return;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Check/Check/B-small-practice.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Check/Check/ans2.txt","w",stdout);
    int T,N;
    double p[250],t[250];
    int counter;
    cin>>T;
    debug = 0;
    for(int c=0;c<T;c++){
        cin>>N>>M;
        for(int i=0;i<N;i++)cin>>p[i];
        sort(p,p+N);
        counter = 0;
        maximum = 0;
        for(int i=0;i<M;i++){arr[i]=0;}
        for(int i=0;i<M/2;i++){
            t[counter++] = p[i];
        }
        for(int i=N-1;i>N-M/2-1;i--){
            t[counter++] = p[i];
        }
        //for(int i = 0;i<M;i++)cout<<t[i];cout<<endl;
        perm(t,M/2,0);
        printf("Case #%d: %.8lf\n", c+1, maximum);
        
    }
    return 0;
}
