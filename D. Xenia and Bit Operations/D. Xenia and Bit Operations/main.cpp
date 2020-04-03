#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
long max_size;

int getMid(int s, int e) {  return s + (e -s)/2;  }

double Log2(double n)
{
    return log(n) / log((double)2);
}

void update (int *st,long a, int p,bool op){
    st[a] = p;
    if(a==0){
        return;
    }
    int val;
    if(op){
         val = st[2*((a-1)/2)+1] | st[2*((a-1)/2)+2];
    }
    else{
         val = st[2*((a-1)/2)+1] ^ st[2*((a-1)/2)+2];
    }
    update(st,(a-1)/2,val,!op);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si,bool op)
{
        if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    
    int mid = getMid(ss, se);
    if(op){
        st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1,!op) | constructSTUtil(arr, mid+1, se, st, si*2+2,!op);
    }
    else{
        st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1,!op) ^ constructSTUtil(arr, mid+1, se, st, si*2+2,!op);
    }
    return st[si];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(Log2(n)));
    max_size = 2*(long)pow((double)2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0,x%2!=0);
    return st;
}

int main()
{
    freopen("/Users/shashanksaurabh/Desktop/Journey/D. Xenia and Bit Operations/D. Xenia and Bit Operations/input.txt","r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/D. Xenia and Bit Operations/D. Xenia and Bit Operations/output.txt","w", stdout);
    int n, m,arr[131072],a,b;
    cin>>n>>m;
    n=pow((double)2, n);
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }
    int *st = constructST(arr, n);
    for (int i =0 ; i<m; ++i) {
        cin>>a>>b;
        update(st,max_size/2 +a -1,b,true);
        cout<<st[0]<<endl;
    }
    return 0;
}
