//
//  main.cpp
//  Ant
//
//  Created by Shashank Saurabh on 5/5/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;
int maxi,N;

void count(int *ant,int current,int pos, int count){
    if(pos==N){
        maxi=maxi>count?maxi:count;
        return;
    }
    if(current <ant[pos]){
        int val = ant[pos];
        count(ant,val,pos+1,count+1);
    }
    count(ant,current,pos+1,count);
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for (int testCase=1; testCase<=T; ++testCase) {
        maxi=0;
        cin>>N;
        int *ant=new int[N];
        for (int i=0; i<N; i++) {
            cin>>ant[i];
        }
        count(ant,0,0,0);
        cout<<"Case #"<<testCase<<": "<<maxi;
    }
    return 0;
}
