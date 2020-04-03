//
//  main.cpp
//  Apac_gfiles
//
//  Created by Shashank Saurabh on 18/10/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//  main(int argc, const char * argv[]) {
//freopen("/Users/shashanksaurabh/Desktop/Journey/Google_apac_3/Google_apac_3/text1.txt","r",stdin);
//ofstream lemming;
//lemming.open("/Users/shashanksaurabh/Desktop/Journey/Google_apac_3/Google_apac_3/ans.txt");

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <list>
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
long long int MAX = 1000000007;
int getAns(char a, char b, char c) {
    if (a==b && b==c && a==c) return 1;
    else if (a!=b && b!=c && a!=c) return 3;
    else return 2;
}

int main() {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Google_apac_3/Google_apac_3/text1.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Google_apac_3/Google_apac_3/ans.txt", "w", stdout);
    int t,n,x,k,a,b,c;
    cin >> t;
    for (int i=1;i<=t;i++) {
        cin>>n>>x>>k>>a>>b>>c;
        vector<long double> val(10^6);
        for(int j=0;j<(10^6);j++)val[i]=0;
        cout<<n;
        list<int> p;
        p.push_back(x);
        long double ex=0;
        for(int j=1;j<=n;j++)
        {
            for(list<int>::iterator it = p.begin(); it != p.end(); it++){
                
                int value =(*it),v1,v2,v3;
                v1=value & k;
                v2=value | k;
                v3=value ^ k;
                
                if(val[v1]!=0)
                    val[v1]= val[v1] + a/100;
                else if(val[v1]==0){
                    val[v1]=a;
                    p.push_back(v1);
                }
                
                if(val[v2]!=0)
                    val[v2]= val[v2] + b/100;
                else if(val[v2]==0) {
                    val[v2]=b;
                    p.push_back(v2);
                }
                
                if(val[v3]!=0)
                    val[v3]=val[v3] + c/100;
                else if (val[v3]==0){
                    val[v3]=c;
                    p.push_back(v3);
                }
                
            }
        }
        for(list<int>::iterator it = p.begin(); it != p.end(); ++it){
            ex=ex+ val[*it]*(*it);
        
        }cout << "Case #" << i << ": " << x << endl;
        }
        
    }
