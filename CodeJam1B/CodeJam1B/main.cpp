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

int debug;

int f(char s){return s-'A';}

void cleanup(int *a , char *s ,int times){
    int counter;
    for(int i=0;i<times;i++){
        counter = 0;
        while(s[counter]!='\0')--a[s[counter++] - 'A'];
    }
    if(debug == 1){
        cout<<"--------------------Removal"<<endl;
        for(int j=0;j<26;j++)cout<<a[j]<<'\t';cout<<endl;
    }
    
}

void p(int num,int times){
    for(int i=0;i<times;i++)cout<<num;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/CodeJam1B/CodeJam1B/A-large-practice.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/CodeJam1B/CodeJam1B/ansSmall.txt","w",stdout);
    int T,a[26],counter,num[10];
    char S[2050];
    debug = 0;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>S;
        for(int j=0;j<10;j++)num[j]=0;
        for(int j=0;j<26;j++)a[j]=0;
        counter = 0;
        while(S[counter]!='\0')++a[S[counter++] - 'A'];
        if(debug == 1){for(int j=0;j<26;j++)cout<<a[j]<<'\t';cout<<endl;}
        if(a[f('Z')]!=0){num[0]+=a[f('Z')];cleanup(a,"ZERO",a[f('Z')]);}
        if(a[f('W')]!=0){num[2]+=a[f('W')];cleanup(a,"TWO",a[f('W')]);}
        if(a[f('U')]!=0){num[4]+=a[f('U')];cleanup(a,"FOUR",a[f('U')]);}
        if(a[f('O')]!=0){num[1]+=a[f('O')];cleanup(a,"ONE",a[f('O')]);}
        if(a[f('R')]!=0){num[3]+=a[f('R')];cleanup(a,"THREE",a[f('R')]);}
        if(a[f('F')]!=0){num[5]+=a[f('F')];cleanup(a,"FIVE",a[f('F')]);}
        if(a[f('X')]!=0){num[6]+=a[f('X')];cleanup(a,"SIX",a[f('X')]);}
        if(a[f('G')]!=0){num[8]+=a[f('G')];cleanup(a,"EIGHT",a[f('G')]);}
        if(a[f('V')]!=0){num[7]+=a[f('V')];cleanup(a,"SEVEN",a[f('V')]);}
        if(a[f('I')]!=0){num[9]+=a[f('I')];cleanup(a,"NINE",a[f('I')]);}
        if(debug == 1){
            cout<<"Final------------------------------"<<endl;
            for(int j=0;j<10;j++)cout<<num[j]<<'\t';
            cout<<endl;}
        printf("Case #%d: ", i+1);
        for(int j=0;j<10;j++){
            p(j,num[j]);
        }
        cout<<endl;
    }
    
    
    //printf("Case #%d: %.8lf\n", c+1, temp);
    return 0;
}
