//
//  main.cpp
//  optimize!!!!
//
//  Created by Shashank Saurabh on 4/14/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

static int INF = 1000000009;

void build(int *st1,int N){
    for (int i = N-1; i>=1; --i) {st1[i] = min(st1[i<<1],st1[i<<1 |1]);}
}

void update_min(int *st2,int *st1,int N,int pos){
    for(; pos>1; pos>>=1) {st1[pos>>1] = min(st1[pos]+st2[pos],st1[pos^1]+st2[pos^1]);}
}

void update(int *st2,int *st1,int N,int l,int r, int val){
    if(l>r || l<0 || r>N-1)return;
    if(r>=0){st2[r+N]+=val;update_min(st2,st1,N,r+N);}
    for (l+=N,r+=N; l<r; l>>=1,r>>=1){
        if(l&1){
            st2[l]+=val;
            update_min(st2,st1,N,l);
            ++l;
        }
        if(r&1){
            --r;
            st2[r]+=val;
            update_min(st2,st1,N,r);
        }
    }
    //for (int i=0; i<2*N; i++) {
        //cout<<st1[i]<<'\t';
    //}
    //cout<<endl;
    //for (int i=0; i<2*N; i++) {
        //cout<<st2[i]<<'\t';
    //}
    //cout<<endl<<endl;
}

void initialize(int *st1,int *st2,int N){
    for (int i = 0; i<2*N; i++) {st1[i]=0;st2[i]=0;}
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/optimize!!!!/optimize!!!!/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/optimize!!!!/optimize!!!!/output.txt", "w", stdout);
    int N,M,K,ans=0;
    cin>>N>>M>>K;
    int *A = new int[N];
    int *B = new int[(M+1)];
    int *st1 = new int[2*(M+1)];
    int *st2 = new int[2*(M+1)];
    for (int i=0; i<M; i++)cin>>B[i];B[M++]=INF;
    for (int i=0; i<N; i++)cin>>A[i];
    sort(B,B+M);
    for (int i=0; i<N; i++)A[i] = (int)(lower_bound(B, B+M, K-A[i]) - B);
    initialize(st1, st2, M);
    for (int i=M; i<2*M; i++) {st1[i] = 2*M-i-1;}
    build(st1,M);
    for (int i=0; i<M-2; i++)
        update(st2, st1, M, 0, A[i], -1);
    for (int i=M-2; i<N; i++) {
        update(st2, st1, M, 0, A[i], -1);
        if(st1[1]>=0)++ans;
        update(st2, st1, M, 0, A[i-M+2],1);
    }
    cout<<ans<<endl;
    return 0;
}
