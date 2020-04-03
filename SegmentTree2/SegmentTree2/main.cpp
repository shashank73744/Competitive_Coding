//
//  main.cpp
//  SegmentTree2
//
//  Created by Shashank Saurabh on 1/20/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
long nodes;


int getMid (int s, int e){
    return {s + (e-s)/2};
}

void updateUtill(int arr[] , int sr ,int en , int rs, int se , int val,int no, int *st){
    if(sr>=rs && en<=se){
        st[sr] = val;
        return ;
    }
    int mid =getMid(rs,se);
    if(sr<=se &&  en>=sr){
        updateUtill(arr, sr,en ,rs ,mid,val,2*no+1,st);
        updateUtill(arr, sr,en ,mid + 1 ,se,val,2*no+2,st);
    }
    return;
}

void update (int arr[],int n ,int sr,int en, int val,int *st){
    updateUtill(arr, sr,en ,0 ,n-1,val,0,st);
}

int constructUtill (int arr[], int sr, int en , int no,int *st){
    if(sr == en ){
        st[no]= arr[sr];
        return st[no];
    }
    int mid = getMid(sr,en);
    st[no] = constructUtill(arr, sr,mid , 2*no + 1,st) + constructUtill(arr, mid+1,en , 2*no + 2,st);
    return st[no];
}


int * construct (int n , int arr[]){
    int levels = (int)ceil(log2(n));
    nodes =  2*(long)pow((double)levels,2) - 1;
    int *st = new int[nodes];
    constructUtill(arr,0 ,n-1,0,st);
    return st;
}


int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/SegmentTree2/SegmentTree2/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/SegmentTree2/SegmentTree2/output.txt", "w", stdout);
    int T,n , arr[13102], *st;
    cin>>T>>n;
    for (int i =0 ; i<n; i++) {
        cin>>arr[i];
    }
    for(int i= 0;i<n;i++){
        cout<<arr[i]<<'\t';
    }
    st = construct(n ,arr);
    for(int i= 0;i<nodes;i++){
        cout<<st[i]<<'\t';
    }
    update(arr,n, 2,5 ,0,st);
    cout<<endl;
    for(int i= 0;i<nodes;i++){
        cout<<st[i]<<'\t';
    }
    return 0;
}
