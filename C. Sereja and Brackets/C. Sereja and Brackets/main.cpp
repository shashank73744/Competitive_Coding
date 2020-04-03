//
//  main.cpp
//  C. Sereja and Brackets
//
//  Created by Shashank Saurabh on 3/12/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>

using namespace std;

void ops (int **st, int p ,int cl ,int cr){
    if(cl>cr){
        int t = cl;
        cl = cr;
        cr = t;
    }
    int newadd = min(st[cl][1],st[cr][2]);
    st[p][0] = st[cl][0] + st[cr][0] + 2*newadd ;
    st[p][1] = st[cl][1] + st[cr][1] - newadd ;
    st[p][2] = st[cl][2] + st[cr][2] - newadd ;
}

void build(int **st, int n){
    for(int i = n-1 ; i>0;--i)ops(st, i, i<<1, i<<1|1);
}

void update(int **st , int n ,int pos , int val1, int val2, int val3){
    pos+=n;
    st[pos][0] = val1;
    st[pos][1] = val2;
    st[pos][2] = val3;
    for(;pos>1;pos>>=1)ops(st,pos>>1,pos,pos^1);
}

int querry(int **st , int n , int l ,int r){
    int resl[3],resr[3];
    resl[0]=0;resl[1]=0;resl[2]=0;
    resr[0]=0;resr[1]=0;resr[2]=0;
    if(l<=r && r>=0){
        resr[0] = st[n+r][0];
        resr[1] = st[n+r][1];
        resr[2] = st[n+r][2];
    }
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1){
            resl[0] = resl[0] + st[l][0] + 2*min(resl[1] ,st[l][2]);
            resl[1] = resl[1] + st[l][1] - min(resl[1] ,st[l][2]);
            resl[2] = resl[2] + st[l][2] - min(resl[1] ,st[l][2]);
            ++l;
        }
        if(r&1){
            --r;
            resr[0] = st[r][0] + resr[0] + 2*min(st[r][1], resr[2]);
            resr[1] = st[r][1] + resr[1] - min(st[r][1] ,resr[2]);
            resr[2] = st[r][2] + resr[2] - min(st[r][1] ,resr[2]);
            
        }
    }
    return (resl[0] + resr[0] + 2*min(resl[1],resr[2]));
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/C. Sereja and Brackets/C. Sereja and Brackets/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/C. Sereja and Brackets/C. Sereja and Brackets/output.txt", "w", stdout);
    char *str = new char[1000001];
    int m,l,r,ans=0;
    int n=0;
    cin>>str;
    cin>>m;
    for (; str[n]!='\0'; ++n) {
    }
    int **st = new int*[2*n];
    for(int i = 0; i < 2*n; ++i)
        st[i] = new int[3];
    for(int i=0;i<n;i++){
        if(str[i] == '('){
            st[n+i][0]=0;
            st[n+i][1]=1;
            st[n+i][2]=0;
        }
        else if(str[i] == ')'){
            st[n+i][0]=0;
            st[n+i][1]=0;
            st[n+i][2]=1;
        }
    }
    build(st,n);
    for (int i=0; i<m; ++i) {
        cin>>l>>r;
        ans =querry(st,n,l-1,r-1);
        cout<<(ans)<<endl;
    }
    return 0;
}
