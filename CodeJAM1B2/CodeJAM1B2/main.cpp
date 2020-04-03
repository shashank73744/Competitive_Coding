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
    freopen("/Users/shashanksaurabh/Desktop/Journey/CodeJam1B2/CodeJam1B2/B-small-practice.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/CodeJam1B2/CodeJam1B2/ansSmall.txt","w",stdout);
    int T,counter,max;
    char C[20],J[20];
    debug = 0;
    cin>>T;
    for(int i=0;i<T;i++){
        counter =0;
        max=0;
        cin>>C>>J;
        //cout<<C<<" "<<J<<endl;
        while(C[counter]!='\0'){
            if(debug==1)cout<<C[counter]<<'\t'<<J[counter]<<endl<<"max = "<<max<<endl;
            if(max==0){
                if(C[counter]=='?' && J[counter]=='?'){C[counter]='0';J[counter]='0';}
                else if(C[counter]=='?' && J[counter]!='?'){C[counter]=J[counter];}
                else if(C[counter]!='?' && J[counter]=='?'){J[counter]=C[counter];}
                else if(C[counter]!='?' && J[counter]!='?' && C[counter]!=J[counter]){
                    max = -1;
                    if(strcmp(&C[counter],&J[counter])>0)max=1;
                }
            }
            else if(max==1){
                if(C[counter]=='?')C[counter]='0';
                if(J[counter]=='?')J[counter]='9';
            
            }
            else if(max==-1){
                if(C[counter]=='?')C[counter]='9';
                if(J[counter]=='?')J[counter]='0';
                
            }
            if(debug==1)cout<<C[counter]<<'\t'<<J[counter]<<endl<<"max = "<<max<<endl;
            ++counter;
            
        }
        printf("Case #%d: ",i+1);
        cout<<C<<" "<<J<<endl;
        
        
    }
    
    
    //printf("Case #%d: %.8lf\n", c+1, temp);
    return 0;
}
