//
//  main.cpp
//  E. Copying Data
//
//  Created by Shashank Saurabh on 3/14/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

//need provide x,y in array format;
void update( int **st,int n,int cp[4]){
    int l = cp[1],r=cp[1]+cp[2];
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1){
            st[l][0] =cp[0];st[l][1]=cp[1];st[l][2]=cp[2];st[l][3]=cp[3];
            ++l;
        }
        if(r&1){
            --r;
            st[r][0]=cp[0];st[r][1]=cp[1];st[r][2]=cp[2];st[r][3]=cp[3];
        }
    }
}

int * querry(int **st,int n,int b){
    b+=n;
    int cp[4];
    cp[0]=st[b][0];cp[1]=st[b][1];cp[2]=st[b][2];cp[3]=st[b][3];
    for (; b>0;b>>=1) {
        if(st[b][3]>cp[3]){
            cp[0]=st[b][0];
            cp[1]=st[b][1];
            cp[2]=st[b][2];
            cp[3]=st[b][3];
        }
    }
    return cp;
}

int main(int argc, const char * argv[]){
    freopen("/Users/shashanksaurabh/Desktop/Journey/E. Copying Data/E. Copying Data/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/E. Copying Data/E. Copying Data/output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    int *cpq,pos,type,cp[4],ans;
    int *a=new int[n];
    int *b=new int[n];
    int **st = new int*[2*n];
    for (int i=0; i<2*n; i++) {
        st[i] = new int[4];
        st[i][3]=0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=m;i++){
        cin>>type;
        if(type == 2){
            cin>>pos;--pos;
            cpq = querry(st, n, pos);
            //cout<<cpq[0]<<'\t'<<cpq[1]<<'\t'<<cpq[2]<<'\t'<<cpq[3]<<endl;
            if(cpq[3]==0)ans=b[pos];
            else{
                ans = a[cpq[0]+pos-cpq[1]];
            }
            cout<<ans<<endl;
        }
        else{
            cin>>cp[0]>>cp[1]>>cp[2];
            --cp[0];--cp[1];
            cp[3]=i;
            update(st, n, cp);
        }
    }
    return 0;
}













