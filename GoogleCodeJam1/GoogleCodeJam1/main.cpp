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

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/GoogleCodeJam1/GoogleCodeJam1/B-small-practice.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/GoogleCodeJam1/GoogleCodeJam1/ansSmall.txt","w",stdout);
    int T,N,M,m,a,b;
    double p[250],t[2][100],d[2][100],temp,tie[2],t2[2][100],d2[2][100],tie2[2];
    cin>>T;
    debug = 0;
    for(int c=0;c<T;c++){
        cin>>N>>M;
        if(debug == 1)cout<<"TestCase "<<c<<" "<<N<<" "<<M<<"*****************************************************************"<<endl;
        m=0;
        for(int i=0;i<N;i++){
            cin>>p[i];
        }
        sort(p,p+N);
        if(debug == 1){
            cout<<"Sorted Order------------------------------------------------------"<<endl;
            for(int i=0; i<N; i++){
                cout<<p[i]<<endl;
            }
            cout<<"------------------------------------------------------------------"<<endl;
        }
        for(int i=0;i<100;i++){t[0][i]=0;t[1][i]=0;d[0][i]=0;d[1][i]=0;}
        t[0][0]=p[0];
        d[0][0]=1-p[0];
        tie[0] = 0;
        tie[1] = 0;
        for(int i=1;i<M/2;i++){
            a = i%2;
            b = (i-1)%2;
            tie[a]=0;
            for(int j =0;j<M/2;j++){t[a][j]=0;d[a][j]=0;}
            t[a][0] += tie[b]*p[i];
            for(int j =1;j<M/2;j++)t[a][j] += t[b][j-1]*p[i];
            tie[a] += d[b][0]*p[i];
            for(int j =0;j<M/2-1;j++)d[a][j] += d[b][j+1]*p[i];
            
            d[a][0] += tie[b]*(1-p[i]);
            for(int j =1;j<M/2;j++)d[a][j] += d[b][j-1]*(1-p[i]);
            tie[a] += t[b][0]*(1-p[i]);
            for(int j =0;j<M/2-1;j++)t[a][j] += t[b][j+1]*(1-p[i]);
            if(debug == 1){
                for(int j =0;j<M/2;j++)cout<<'\t'<<t[a][j];cout<<endl;
                for(int j =0;j<M/2;j++)cout<<'\t'<<d[a][j];cout<<endl;
                cout<<'\t'<<tie[a]<<endl<<endl;
            }
        }
        for(int i=0;i<100;i++){t2[0][i]=0;t2[1][i]=0;d2[0][i]=0;d2[1][i]=0;}
        t2[(N-1)%2][0]=p[N-1];
        d2[(N-1)%2][0]=1-p[N-1];
        tie2[0] = 0;
        tie2[1] = 0;
        if(debug == 1)cout<<"Bottom Ones ---------------------------------------------"<<endl;
        for(int i=N-2;i>N-M/2-1;i--){
            a = i%2;
            b = (i+1)%2;
            tie2[a]=0;
            for(int j =0;j<M/2;j++){t2[a][j]=0;d2[a][j]=0;}
            t2[a][0] += tie2[b]*p[i];
            for(int j =1;j<M/2;j++)t2[a][j] += t2[b][j-1]*p[i];
            tie2[a] += d2[b][0]*p[i];
            for(int j =0;j<M/2-1;j++)d2[a][j] += d2[b][j+1]*p[i];
            
            d2[a][0] += tie2[b]*(1-p[i]);
            for(int j =1;j<M/2;j++)d2[a][j] += d2[b][j-1]*(1-p[i]);
            tie2[a] += t2[b][0]*(1-p[i]);
            for(int j =0;j<M/2-1;j++)t2[a][j] += t2[b][j+1]*(1-p[i]);
            if(debug == 1){
                for(int j =0;j<M/2;j++)cout<<'\t'<<t2[a][j];cout<<endl;
                for(int j =0;j<M/2;j++)cout<<'\t'<<d2[a][j];cout<<endl;
                cout<<'\t'<<tie2[a]<<endl<<endl;
            }
        }
        a = (M/2-1)%2;
        b = (N-M/2)%2;
        if(debug == 1)cout<<"Used for Final Calculation -------------------------------"<<endl;
        if(debug == 1){
            for(int i =0;i<M/2;i++)cout<<'\t'<<t[a][i];cout<<endl;
            for(int i =0;i<M/2;i++)cout<<'\t'<<d[a][i];cout<<endl;
            cout<<'\t'<<tie[a]<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
        }
        if(debug == 1){
            for(int i =0;i<M/2;i++)cout<<'\t'<<t2[b][i];cout<<endl;
            for(int i =0;i<M/2;i++)cout<<'\t'<<d2[b][i];cout<<endl;
            cout<<'\t'<<tie2[b]<<endl;
        }
        temp = tie[a]*tie2[b];
        for(int i=0;i<M/2;i++){
            temp += t[a][i]*d2[b][i] + t2[b][i]*d[a][i];
        }
        printf("Case #%d: %.8lf\n", c+1, temp);
        
    }
    return 0;
}
