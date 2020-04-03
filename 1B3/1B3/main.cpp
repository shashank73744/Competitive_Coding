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
#include <string>
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

int debug,N;
char S1[16][22],S2[16][22],fake[16];

int find(char *s1){
    int count =0;
    for(int i =0 ;i<N;i++){
        if(strcmp(s1,S1[i])==0 && fake[i]==0)++count;
    }
    return count;
}

int find2(char *s1){
    int count =0;
    for(int i =0 ;i<N;i++){
        if(strcmp(s1,S2[i])==0 && fake[i]==0)++count;
    }
    return count;
}


int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/1B3/1B3/C-small-practice.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/1B3/1B3/ansSmall.txt","w",stdout);
    int T,fa;
    debug = 0;
    cin>>T;
    for(int i=0;i<T;i++){
        fa=0;
        cin>>N;
        for(int j=0;j<N;j++){fake[j]=0;}
        for(int j=0;j<N;j++){
            cin>>S1[j]>>S2[j];
        }
        for(int j=0;j<N;j++){
            if(find(S1[j])>1 && find2(S2[j])>1 ){++fa;fake[j]=1;cout<<S1[j]<<'\t'<<S2[j]<<endl;}

        }
        printf("Case #%d: ",i+1);
        cout<<fa<<endl;
        
        
    }
    
    
    //printf("Case #%d: %.8lf\n", c+1, temp);
    return 0;
}
