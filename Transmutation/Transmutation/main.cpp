//
//  main.cpp
//  Transmutation
//
//  Created by Shashank Saurabh on 5/13/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include<iostream>

using namespace std;

bool metals_checked[100];

bool combinationPossible (int M, int *metals,int formula[100][2],int metal,int grams){
    if(metals_checked[metal])return false;
    if(metals[metal]>= grams){
        metals[metal]-=grams;
        return true;
    }
    grams = grams - metals[metal];
    metals[metal] = 0;
    metals_checked[metal] = true;
    return (combinationPossible(M, metals, formula, formula[metal][0], grams) && combinationPossible(M, metals, formula, formula[metal][1], grams));
}



int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Transmutation/Transmutation/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Transmutation/Transmutation/output.txt", "w", stdout);
    int T,M,metals[100],formula[100][2],metals_rep[100],l,r,mid;
    cin>>T;
    for (int testCase =1; testCase<=T; ++testCase) {
        cin>>M;l=0;r=1000000000;
        for (int i=0; i<M; i++) {
            cin>>formula[i][0]>>formula[i][1];
            --formula[i][0];--formula[i][1];
        }
        for (int i=0; i<M; i++) {
            cin>>metals[i];
        }
        while (l<r) {
            mid=(l+r+1)>>1;
            for (int i=0; i<M; i++) {
                metals_rep[i]=metals[i];
                metals_checked[i]=false;
            }
            if(combinationPossible(M, metals_rep, formula, 0, mid)){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        cout<<"Case #"<<testCase<<": "<<l<<endl;
    }
    return 0;
}
