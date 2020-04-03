//
//  main.cpp
//  Trouble Sort
//
//  Created by Shashank Saurabh on 4/7/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

void swap (int &a,int &b){
    int t=b;
    b =a ;
    a = t;
}

int main() {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Trouble Sort Testing/Trouble Sort Testing/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Trouble Sort Testing/Trouble Sort Testing/output.txt", "w", stdout);
    int V0[1000];
    int T,N=0;
    cin>>T;
    for (int i=1; i<=T; i++) {
        cin>>N;
        for (int j=0; j<N; j++) {
            cin>>V0[j];
        }
        bool done = false;
        while (!done){
            done = true;
            for (int i = 0; i < N-2; i++){
                if (V0[i] > V0[i+2]){
                    done = false;
                    swap(V0[i],V0[i+2]);
                }
            }
        }
        for (int i=0; i<N; i++) {
            cout<<V0[i]<<'\t';
        }
        cout<<endl;
        
    }
    return 0;
}
