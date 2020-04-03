//
//  main.cpp
//  Codechef_fruit
//
//  Created by Shashank Saurabh on 17/10/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <fstream>

using namespace std;
int section(long num, int level )
{
    long n = pow(3,level -1);
    if(num< n +1)
        return 0;
    if (num > 2*n)
        return 2;
    else
        return 1;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Codechef_fruit/Codechef_fruit/test.txt","r",stdin);
    
    int n,id_l,id_r,num_l,num_r,l,l1,id=1;
    int Ex[3][3]={0,1,2,1,0,0,1,2,1};
    long long N[3][n][3];
    char s[10];
    N[0][0][0]=1;N[0][0][1]=0;N[0][0][2]=0;
    N[1][0][0]=0;N[1][0][1]=1;N[1][0][2]=0;
    N[2][0][0]=0;N[2][0][1]=0;N[2][0][2]=2;
    cin>>s;
    cin>>num_l;
    cin>>num_r;
    cin>>n;
    queue<int> p;
    //puts(s);
    //cout<<num_l<<'\t'<<num_r;
    
    for (int i=1; i<=n; i++) {
        N[0][i][0]=N[0][i-1][0] + 2*N[0][i-1][1];
        N[0][i][1]=N[0][i-1][0] + 2*N[0][i-1][2];
        N[0][i][2]=N[0][i-1][0] + N[0][i-1][2];
        N[1][i][0]=N[1][i-1][0] + 2*N[1][i-1][1];
        N[1][i][1]=N[1][i-1][0] + 2*N[1][i-1][2];
        N[1][i][2]=N[1][i-1][0] + N[1][i-1][2];
        N[2][i][0]=N[2][i-1][0] + 2*N[2][i-1][1];
        N[2][i][1]=N[2][i-1][0] + 2*N[2][i-1][2];
        N[2][i][2]=N[2][i-1][0] + N[2][i-1][2];
    }
    
    if(strcmp(s,"apple")==0)
    {
        id=0;
    }
    if(strcmp(s,"banana")==0)
    {
        id=1;
    }
    if(strcmp(s,"kiwi")==0)
    {
        id=2;
    }
    //cout<<id<<'\t'<<N[0][id];
    id_l=Ex[id][section(num_l,n)];
    id_r=Ex[id][section(num_r,n)];
    //cout<<id_r;
    if ((section(num_r,n)-section(num_l,n))==1) {
        p.push(n-1);
        p.push(Ex[id][1]);
    }
    
    l=n-1;num_l=num_l - section(num_l,l);
    for (int i=0; i<n-1; i++) {
        int s=section(num_l,l);
        l--;
        num_l=num_l-s*pow(3, l);
        int k=s;
        cout<<s<<'\t'<<l<<endl;
        while (k<=2) {
            p.push(l);
            p.push(Ex[id_l][k]);
            k++;
        }
        id_l=Ex[id_l][s];
    }
    
    for (int i=0; i<n; i++) {
        int s=section(num_r,l1);
        l1--;
        num_r=num_r-s*pow(3, l1);
        int k=s;
        while (k>=0) {
            p.push(l);
            p.push(Ex[id_r][k]);
            k--;
        }
        id_r=Ex[id_r][s];
    }
    
    /*while (!p.empty()) {
        int level,fruit;
        level=p.front();
        p.pop();
        fruit=p.front();
        p.pop();
        cout<<level<<'\t'<<fruit<<endl;
    }*/
    
    //cout<<sum[0]<<'\t'<<sum[1]<<'\t'<<sum[2];
    /*for (int i=0; i<10; i++) {
        cout<<N[i][0]<<'\t'<<N[i][1]<<'\t'<<N[i][2]<<endl;
    }*/
    return 0;
}
