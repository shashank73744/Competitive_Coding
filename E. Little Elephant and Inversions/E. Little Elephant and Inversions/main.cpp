//
//  main.cpp
//  E. Little Elephant and Inversions
//
//  Created by Shashank Saurabh on 3/23/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define HASH_COUNT 500000

void update(int *st,int n,int pos,int val){
    pos+=n;
    st[pos]+=val;
    for(;pos>1;pos>>=1){
        st[pos>>1] = st[pos] + st[pos^1];
    }
}

int querry (int *st,int n,int l,int r){
    int res = 0;
    if(l<=r && r>=0)res+=st[r+n];
    for (l+=n,r+=n; l<r; l>>=1,r>>=1) {
        if(l&1)res+=st[l++];
        if(r&1)res+=st[--r];
    }
    return res;
}

int hashFunction1(long pos){return (int)pos%499999;}

void clearHashTable(long **ht){for (int i=0; i<HASH_COUNT; i++) {ht[i][0] = -1;ht[i][1] =0;}}

void update(long **ht,long pos ,int val){
    int ct = hashFunction1(pos);
    while (ht[ct][0] !=-1 && ht[ct][0] !=pos)ct=((ct+1)%HASH_COUNT);
    ht[ct][0]=pos;
    ht[ct][1]=val;
}

int querry(long **ht,long pos){
    int ct = hashFunction1(pos);
    while (ht[ct][0] !=-1 && ht[ct][0] !=pos)ct=((ct+1)%HASH_COUNT);
    return (int)ht[ct][1];
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/E. Little Elephant and Inversions/E. Little Elephant and Inversions/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/E. Little Elephant and Inversions/E. Little Elephant and Inversions/output.txt", "w", stdout);
    int n ,lt=0,counter=0;
    long prev=-1;
    long long ans=-1,ic=0,k;
    cin>>n>>k;
    int *st1=new int[2*n];
    int *st2=new int[2*n];
    long *arr = new long[n];
    long *arr2 = new long[n];
    long **ht = new long*[HASH_COUNT];
    for (int i=0; i<HASH_COUNT; i++) {
        ht[i]=new long[2];
    }
    for (int i=0; i<n; i++){cin>>arr[i];arr2[i]=arr[i];}
    for (int i=0; i<2*n; i++) {st1[i]=0;st2[i]=0;}
    sort(arr2,arr2+n);
    clearHashTable(ht);
    for (int i=0; i<n; i++) {
        if(prev!=arr2[i]){
            update(ht,arr2[i],counter);
            prev = arr2[i];
            ++counter;
        }
    }
    for (int i=0; i<n; i++) {arr[i]=querry(ht,arr[i]);}
    update(st1,n,(int)arr[0],1);
    update(st2,n,(int)arr[n-1],1);
    ic+=(long long)querry(st1, n,(int)arr[0]+1,n-1)+ (long long)querry(st2, n, 0, (int)arr[0]-1);
    if(ic>k){
        cout<<0;
    }
    else{
        for (int i=1; i<n-1; i++) {
            update(st1,n,(int)arr[i],1);
            ic+=(long long)querry(st1, n,(int)arr[i]+1,n-1)+ (long long)querry(st2, n, 0, (int)arr[i]-1);
            if(ic>k){ans=i;lt=i;break;}
        }
        if(ans == -1){
            ans = ((long long)n*(long long)(n-1))/2;
        }
        else{
            update(st1, n, (int)arr[lt], -1);
            ic-=((long long)querry(st1,n,(int)arr[lt]+1,n-1)+ (long long)querry(st2,n,0,(int)arr[lt]-1));
            --lt;
            for (int i=n-2;i>lt&&i>1; --i) {
                update(st2, n, (int)arr[i], 1);
                ic+=(long long)querry(st1, n, (int)arr[i]+1, n-1) + (long long)querry(st2, n, 0, (int)arr[i]-1);
                while (ic>k && lt>0) {
                    update(st1, n, (int)arr[lt], -1);
                    ic-=((long long)querry(st1,n,(int)arr[lt]+1,n-1)+ (long long)querry(st2,n,0,(int)arr[lt]-1));
                    --lt;
                }
                if (ic<=k) {
                    ans+=lt+1;
                }
                else break;
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}
