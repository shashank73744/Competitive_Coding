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

int HASHSIZE = 2000000 ;

using namespace std;

int max_nodes;

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

int hashingFunction1(long pos) {
    return pos % 1999957;
}
int hashingFunction2(long pos) {
    return 1;
}
void clearHashMap(long **hashMap) {
    for (int i = 0; i < HASHSIZE; i++) {
        hashMap[i][0] = -1;
        hashMap[i][1] = 0;
    }
}
bool hashUpdate(long **hashMap,long pos, int val) {
    int tg = hashingFunction1(pos);
    int count = HASHSIZE;
    while (hashMap[tg][0] != -1 && hashMap[tg][0] != pos ) {
        tg += hashingFunction2(pos);
        tg%=HASHSIZE;
        --count;
        if (count == 0)return false;
    }
    hashMap[tg][0] = pos;
    hashMap[tg][1] += val;
    return true;
}
long hashRetrieve(long **hashMap,long pos) {
    int tg = hashingFunction1(pos);
    int count = HASHSIZE;
    while (hashMap[tg][0] != pos) {
        --count;
        tg += hashingFunction2(pos);
        tg%=HASHSIZE;
        if (count == 0)return -99;
    }
    return hashMap[tg][1];
}
double lg(int num) {
    return log((double)num) / log((double)2);
}


int * constructStUtil(int n) {
    int* st = new int[2 * n];
    for (int i = n; i<2 * n; i++)st[i] = 0;
    for (int i = n - 1; i>0; --i) {
        st[i] = st[i << 1] + st[i << 1 | 1];
    }
    max_nodes = n;
    return st;
}

void update(int *st, int pos, int val) {
    int p = max_nodes + pos;
    st[p] += val;
    for (; p>1; p >>= 1) {
        st[p >> 1] = st[p] + st[p ^ 1];
    }
    return;
}

int findItems(int *st, int qs, int qe) {
    int ans = 0;
    if (qs <= qe && qe >= 0) ans += st[max_nodes + qe];
    for (qs += max_nodes, qe += max_nodes; qs<qe; qs >>= 1, qe >>= 1) {
        if (qs & 1) {
            ans += st[qs++];
        }
        if (qe & 1) {
            ans += st[--qe];
        }
    }
    return ans;
}
int main() {
    freopen("/Users/shashanksaurabh/Desktop/Journey/hashing/hashing/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/hashing/hashing/output.txt", "w", stdout);
    int n, val, *st;
    long long ans = 0;
    int *arr=new int[1000000];
    int *arr1=new int[1000000];
    int *arr2=new int[1000000];
    long **hashMap = new long*[HASHSIZE];
    for (int i=0; i<HASHSIZE; i++) {
        hashMap[i] = new long[2];
    }
    cin >> n;
    clearHashMap(hashMap);
    for (int i = 0; i<n; i++) {
        cin >> val;
        arr[i] = val;
        if(!hashUpdate(hashMap,val, 1)){
            cout<<"Error"<<endl;
            return i;
        }
        arr1[i] = (int)hashRetrieve(hashMap,val);
    }
    clearHashMap(hashMap);
    for (int i = n-1; i >= 0; i--) {
        if(!hashUpdate(hashMap,arr[i], 1)){
            cout<<"Error"<<endl;
            return i;
        }
        arr2[i] = (int)hashRetrieve(hashMap,arr[i]);
    }
    st = constructStUtil(n);
    for (int i = 0; i<n; i++) {
        update(st, arr2[i] - 1, 1);
    }
    for (int i = 0; i<n; i++) {
        update(st, arr2[i] - 1, -1);
        ans += findItems(st, 0, arr1[i] - 2);
    }
    cout << ans << endl;
    return 0;
}