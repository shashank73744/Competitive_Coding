//
//  main.cpp
//  F. Ant colony
//
//  Created by Shashank Saurabh on 3/13/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>

using namespace std;

long gcd(long a, long b)
{
    if (!a)
        return b;
    return gcd(b%a,a);
}

void build (long **st, int n ){
    for(int i=n-1;i>0;--i){
        long g;
        if(st[i<<1|1][0] > st[i<<1][0] )g= gcd(st[i<<1][0],st[i<<1|1][0]);
        else g= gcd(st[i<<1|1][0],st[i<<1][0]);
        st[i][0]=g;
        st[i][1]=0;
        if(st[i<<1][0] == g)st[i][1]+=st[i<<1][1];
        if(st[i<<1|1][0] == g)st[i][1]+=st[i<<1|1][1];
    }
}

long querry (long **st, int n, int l,int r){
    long resl[2],resr[2],g,ans=0;
    resl[0]=st[l+n][0];resl[1]=0;resr[0]=1;resr[1]=0;
    if(l<=r && r>=0){
        resr[0]=st[r+n][0];
        resr[1]=1;
    }
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1){
            if(resl[0] >st[l][0])g=gcd(st[l][0],resl[0]);
            else g=gcd(resl[0],st[l][0]);
            if(resl[0] != g )resl[1]=0;
            if(st[l][0] == g) resl[1]+=st[l][1];
            resl[0]=g;
            ++l;
            
        }
        if(r&1){
            --r;
            if(resr[0] >st[r][0])g=gcd(st[r][0],resr[0]);
            else g=gcd(resr[0],st[r][0]);
            if(resr[0]!=g)resr[1]=0;
            if(st[r][0] == g)resr[1]+=st[r][1];
            resr[0]=g;
        
        }
    }
    if(resl[0]>resr[0])g=gcd(resr[0],resl[0]);
    else g=gcd(resl[0],resr[0]);
    if(resl[0]==g)ans+=resl[1];
    if(resr[0]==g)ans+=resr[1];
    return ans;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/F. Ant colony/F. Ant colony/input.txt","r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/F. Ant colony/F. Ant colony/output.txt","w",stdout);
    long **st;
    int n,m,l,r;
    cin>>n;
    st =new long*[2*n];
    for(int i=0;i<2*n;i++){
        st[i] = new long[2];
    }
    for(int i=0;i<n;i++){
        cin>>st[i+n][0];
        st[i+n][1] = 1;
    }
    build(st,n);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        cout<<r-l-querry(st,n,l-1,r-1)+1<<endl;
    }
    return 0;
}
