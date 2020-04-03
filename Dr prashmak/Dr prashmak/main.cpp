//
//  main.cpp
//  Pashmak and Parmida's Problem
//
//  Created by Shashank Saurabh on 2/5/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <map>

using namespace std;

int max_nodes;

struct occ
{
    int index, val;
};

int getMid(int s, int e){
    return s + (e - s) / 2;
}

double lg(int num){
    return log((double)num) / log((double)2);
}

int update(map<int, int> &hh, int key){
    std::map<int, int>::iterator i = hh.find(key);
    if (i == hh.end()){
        hh.insert(std::make_pair(key, 1));
        return 1;
    }
    else{
        i->second += 1;
        return i->second;
    }
    
}
bool compareocc(occ i1, occ i2)
{
    return (i1.val < i2.val);
}

int * constructStUtil(int n){
    int* st = new int[2 * n];
    for (int i = n; i<2 * n; i++)st[i] = 0;
    for (int i = n - 1; i>0; --i){
        st[i] = st[i << 1] + st[i << 1 | 1];
    }
    max_nodes = n;
    return st;
}

void update(int *st, int pos, int val){
    int p = max_nodes + pos;
    st[p] += val;
    for (; p>1; p >>= 1){
        st[p >> 1] = st[p] + st[p ^ 1];
    }
    return;
}

int findItems(int *st, int qs, int qe){
    int ans = 0 ;
    if(qs<=qe && qe>0)ans+=st[max_nodes + qe];
    for (qs += max_nodes, qe += max_nodes; qs<qe; qs >>= 1, qe >>= 1){
        if (qs & 1){
            ans += st[qs++];
        }
        if (qe & 1){
            ans += st[--qe];
        }
    }
    return ans;
}
int main() {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Dr prashmak/Dr prashmak/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Dr prashmak/Dr prashmak/ output.txt", "w", stdout);
    map <int, int> hh, hh2;
    int n, val, *st, arr1[10000], arr2[10000], arr[1000000];
    long long ans = 0;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> val;
        arr[i] = val;
        arr1[i] = update(hh, val);
    }
    hh.clear();
    for (int i = n; i >= 0; i--){
        arr2[i] = update(hh, arr[i]);
    }
    //sort(arr,arr+n,compareocc);
    st = constructStUtil(n);
    for (int i = 0; i<n; i++){
        update(st, arr2[i]-1, 1);
    }
    for (int i = 0; i<n; i++) {
        update(st, arr2[i]-1, -1);
        ans += findItems(st, 0, arr1[i] - 2);
    }
    cout << ans << endl;
    return 0;
}