//
//  main.cpp
//  Rounding_Error
//
//  Created by Shashank Saurabh on 4/29/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int current_state(int N,int V){
    int r = (V*100)%N, B=N/2;
    if(r==0)return 0;
    if(r>B)return 1;
    return -1;
}

int number_increase(int N,int V){
    int B = N/2;
    int r = (V*100)%N;
    if(r>B)return 0;
    else if(N%2 !=0) return B-r;
    return B-r+1;
}

bool prime_factor_check(int N){
    while(N%2==0){
        N=N/2;
    }
    while (N%5==0) {
        N=N/5;
    }
    if(N==1)return true;
    return false;
}


int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Rounding_Error/Rounding_Error/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Rounding_Error/Rounding_Error/output.txt", "w", stdout);
    int N,T,L,CS,percentage_change=0,NR[100000],NL,LI,counter,NRZ,pos=0,flag;
    cin>>T;
    for (int testCase=1; testCase <=T; ++testCase){
        percentage_change=0;counter=0;flag=0;
        cin>>N>>L;
        NL=N;
        if(prime_factor_check(N)){
            cout<<100<<endl;
            
        }
        else{
            for (int i=0; i<L; i++) {
                cin>>LI;
                CS = current_state(N,LI);
                NL-=LI;
                if(CS == 1)++percentage_change;
                else if(CS==0){
                    --NL;++percentage_change;
                }
                else{
                    --percentage_change;
                    NR[counter++]=number_increase(N, LI);
                }
            }
            NRZ = number_increase(N, 0);
            for (int i=counter; i<N; i++) {
                NR[i] = NRZ;
            }
            sort(NR,NR+N);
            for (int i=0; i<N; i++) {
                if(NL<NR[i]){pos=i;break;}
                NL-=NR[i];
                percentage_change+=2;
            }
            if(N%2==0 && NL>0){
                for (int i=pos; i<N; i++) {
                    if(NL==NR[i]-1){
                        flag=1;
                    }
                }
            }
            if(flag == 1)++percentage_change;
            cout<<(100+percentage_change)<<endl;
        }
    }
    return 0;
}
