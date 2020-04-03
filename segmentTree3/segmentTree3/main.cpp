//
//  main.cpp
//  segmentTree3
//
//  Created by Shashank Saurabh on 1/25/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

long max_node;

int getMid(int s,int e){
    return (s+ (e-s)/2);
}

double Lg(int n){
    return log((double)n)/log(2);
}

void updateUtill(int *st,int sr,int en,int ts, int te,int node,int val){
    if(ts>=sr && te<=en){
        st[node] =val;
        return;
    }
    int mid = getMid(ts,te);
    if(sr<=te && en>=ts){
        updateUtill(st,sr,en,ts,mid,2*node+1,val);
        updateUtill(st, sr, en, mid + 1, te, 2*node + 2, val);
    }
}

void update(int *st, int sr ,int en, int n, int value ){
    if(sr>en || en>n || sr<0 ){
        return;
    }
    updateUtill(st,sr,en,0, n-1,0,value);
}

int constructUtill (int *st , int sr, int en,int node){
    if(sr == en){
        st[node] = sr;
        return st[node];
    }
    st[node] = -1;
    int mid = getMid(sr, en);
    constructUtill(st, sr, mid, 2*node + 1);
    constructUtill(st, mid + 1, en,  2*node + 2);
    return -1;
}

int * construct(int n ){
    int levels = ceil((Lg((double)n)));
    max_node = 2*pow(2,levels)-1;
    int * st  = new int[max_node];
    constructUtill(st,0,n-1,0);
    return  st;
}

int findBeat(int *st,int in){
    long node = max_node/2 + in;
    while((st[node] == -1 || st[node]!=in) ){
        if(node ==0 ){
            return 0;
        }
        node = node/2;
    }
    return st[node];

}

int main(int argc, const char * argv[]) {
    int n,m,r1,r2,w,*st;
    freopen("/Users/shashanksaurabh/Desktop/Journey/segmentTree3/segmentTree3/input.txt","r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/segmentTree3/segmentTree3/output.txt","w",stdout);
    cin>>n>>m;
    st=construct(n);
    for(int i=0;i<m;i++){
        cin>>r1>>r2>>w;
        update(st,r1-1,r2-1,n,w);
    }
    for (int i=0; i<max_node; i++) {
        cout<<st[i]<<'\t';
    }
    cout<<endl;
    
    for (int i=0; i<n; i++) {
        cout<<findBeat(st,i)<<" ";
    }
    return 0;
}
