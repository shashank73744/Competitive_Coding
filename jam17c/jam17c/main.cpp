//
//  main.cpp
//  jam17c
//
//  Created by Shashank Saurabh on 4/30/17.
//  Copyright (c) 2017 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iomanip>

# define M_PI           3.14159265358979323846 ;
using namespace std;

struct pan {
    long double side;
    long double top;
    int id;
};

pan pk[1000];

bool cmp (pan a, pan b){
    return a.side>b.side;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/jam17c/jam17c/A-large (1).in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/jam17c/jam17c/ans13.txt","w",stdout);
    int T,N,K;
    long double r,h;
    long double sum,ans,top,rtop,lasta;
    cin>>T;
    cout.precision(30);
    //T=1;
    for(int testCase=1;testCase<=T;testCase++){
        cin>>N>>K;
        ans=0;
        for(int i=0;i<N;i++){
            cin>>r>>h;
            pk[i].side=2*r*h;
            pk[i].top=r*r;
            pk[i].id = i;
            //cout<<pk[i].side<<'\t'<<pk[i].top<<endl;
        }
        //cout<<endl;
        sort(pk,pk+N,cmp);
//        for(int i=0;i<N;i++){
//            cout<<pk[i].side<<'\t'<<pk[i].top<<endl;
//        }
//        cout<<endl;
        sum =0;
        lasta =0;
        top=0;
        for(int i= 0;i<K-1;i++){
            top = max(top,pk[i].top);
            sum = sum +pk[i].side;
        }
        for(int i=K-1;i<N;i++){
            rtop = max(top,pk[i].top);
            lasta = max(rtop+pk[i].side,lasta);
        }
        //cout<<ans;
        ans = sum +lasta;
        ans = ans*(double)M_PI;
        //cout<<M_PI;
        cout<<"Case #"<<testCase<<": "<<ans<<endl;
        
    }

    return 0;
}
