//
//  main.cpp
//  E.Enemy is Weak
//
//  Created by Shashank Saurabh on 3/5/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

typedef int64_t ll;

void update(map<int, int> &hh, int key,int value){
    std::map<int, int>::iterator i = hh.find(key);
    if (i == hh.end()){
        hh.insert(std::make_pair(key, value));
    }
    else{
        cout<<"The Elements are not unique please check";
    }
    return;
}

int getValue(map<int, int> &hh, int key){
    std::map<int, int>::iterator i = hh.find(key);
    if (i == hh.end()){
        cout<<"The Element was not found in the map please check";
        return -1;
    }
    else{
        return i->second;
    }
}

void build(int *st,int n){
    for(int i=n-1;i>0;i--)st[i]=st[i<<1] + st[i<<1|1];
}

void update(int *st,int n, int pos , int val){
    int p = n+pos;
    st[p] = val;
    for (; p>1; p>>=1)st[p>>1] = st[p] + st[p^1];
}

int querry(int *st ,int n,int l,int r){
    int res = 0;
    if(l<=r && r>=0) res+=st[n+r];
    for (l+=n,r+=n; l<r; l>>=1,r>>=1) {
        if(l&1)res+=st[l++];
        if(r&1)res+=st[--r];
    }
    return res;
}

int main() {
    freopen("/Users/shashanksaurabh/Desktop/Journey/E.Enemy is Weak/E.Enemy is Weak/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/E.Enemy is Weak/E.Enemy is Weak/output.txt", "w", stdout);
    map <int, int> hh;
    int n;
    ll ans=0;
    cin>>n;
    int *input = new int[n];
    int *sortedInput = new int[n];
    int *st1 = new int[2*n];
    int *st2 = new int[2*n];
    for (int i=0; i<n; i++) {
        cin>>input[i];
        sortedInput[i] = input[i];
    }
    sort(input, input +n);
    for (int i=n;i<2*n;i++){
        st1[i] = 0;
        st2[i] = 1;
    }
    build(st1,n);
    build(st2,n);
    for (int i=0; i<n; i++) {
        update(hh,sortedInput[n-i-1],i);
    }
    for (int i=0; i<n; i++) {
        input[i] = getValue(hh,input[i]);
    }
    for (int i=0; i<n; i++) {
        update(st1,n,input[i],1);
        update(st2,n,input[i],0);
        ans+=querry(st1,n,0,input[i]-1)*querry(st2,n,input[i]+1,n-1);
    }
    //ans =1000000000000000000;
    cout<<ans<<endl;
    return 0;
}
