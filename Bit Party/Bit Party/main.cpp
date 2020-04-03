//
//  main.cpp
//  Bit Party
//
//  Created by Shashank Saurabh on 4/29/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

long possible_bits(int M,int S,int P,long max){
    max -=P;
    long possible = max / (long)S;
    possible = possible <= M ? possible : M;
    possible = possible >=0 ? possible : 0;
    return possible;
}

bool allowed(int R , int B, int C,int **CD,long Max){
    long *bits_from_cashier = new long[C], bits =0;
    for (int i=0; i<C; i++) {
        bits_from_cashier[i]=possible_bits(CD[i][0], CD[i][1], CD[i][2], Max);
    }
    sort(bits_from_cashier,bits_from_cashier + C );
    for (int i=C-1; i>=C-R; --i) {
        bits += bits_from_cashier[i];
    }
    free(bits_from_cashier);
    if(bits>=B)return true;
    return false;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Bit Party/Bit Party/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Bit Party/Bit Party/output.txt", "w", stdout);
    int R,B,C,T;
    cin>>T;
    for (int testCase = 1; testCase<=T; testCase++) {
    cin>>R>>B>>C;
    int**CD = new int*[C];
    for (int i=0; i<C; i++) {
            CD[i] = new int[3];
        }
    for (int i=0; i<C; i++) {
        cin>>CD[i][0]>>CD[i][1]>>CD[i][2];
    }
    long end = 10000000000000, start = 0,mid;
    while (start != end) {
        mid = (start + end)>>1;
        if(allowed(R, B, C, CD, mid)){
            end = mid;
        }
        else{
            start = mid +1;
        }
    }
    cout<<"Case #"<<testCase<<": "<<start<<endl;
        free(CD);
    }
    return 0;
}
