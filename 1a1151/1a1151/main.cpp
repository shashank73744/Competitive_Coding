//
//  main.cpp
//  CodeJAMQualification
//
//  Created by Shashank Saurabh on 4/8/17.
//  Copyright (c) 2017 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

bool cmp(int a, int b){
    return a<b;
}

int debug,N,P,R[50],I[50][50],s[50],ans,r1,r2;

void pos (int q,int req){
    int sr = (int)floor((float).9*q/(float)req),i,f=0;
    int sr2 = (int)ceil((float)1.1*q/(float)req);
    float a,b;
    a=.9*sr*req ,b=1.1*sr*req;
    r1=-1;r2=-1;
    for(i=sr;i<=sr2;i++){
        a=.9*i*req ,b=1.1*i*req;
        if((float)q>=a && (float)q<=b){
            if(f==0){
                r1=i;
                f=1;
            }
            r2=i;
        }
        if(!((float)q>=a && (float)q<=b) && f==1)break;
    }
    r2=i-1;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/1a1151/1a1151/B-small-practice.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/1a1151/1a1151/ans3.txt","w",stdout);
    int T,count,sr,trend1,trend2,f;
    cin>>T;
    //T=1;
    for(int testCase=1;testCase<=T;testCase++){
        cin>>N>>P;
        sr=-1;
        count=0;
        f=0;
        trend1 = -1;
        trend2 = -1;
        ans=0;
        for(int i =0 ;i<N;i++){
            s[i]=0;
        }
        for(int i=0;i<N;i++){
            cin>>R[i];
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<P;j++){
                cin>>I[i][j];
            }
        }
        for(int i=0;i<N;i++){
            sort(I[i],I[i]+P,&cmp);
        }
//        for(int i=0;i<N;i++){
//            for(int j=0;j<P;j++){
//                cout<<I[i][j]<<'\t';
//            }
//            cout<<endl;
//        }
        while(count < P){
            trend1 =-1, trend2= -1;f=1;
            for(int i = count ;i<P;i++){
                pos(I[0][i],R[0]);
                if(r1 != -1){
                    count = i+1;
                    trend1 = r1;
                    trend2 = r2;
                    break;
                }
            }
            if(trend1 == -1)break;
            for(int i = 1;i<N;i++){
                f=0;
                for(int j = s[i];j<P;j++){
                    pos(I[i][j],R[i]);
                    if(r2>=trend1 && r1<=trend2 && r1!=-1){
                        f=1;
                        s[i]=j+1;
                        trend1=max(trend1,r1);
                        trend2=min(trend2,r2);
                        break;
                    }
                }
                if(f==0)break;
            }
            if(f==1){
                ans=ans +1;
            };
        }
        cout<<"Case #"<<testCase<<": "<<ans<<endl;
        
    }
}
