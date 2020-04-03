//
//  main.cpp
//  CodeJAMQualification
//
//  Created by Shashank Saurabh on 4/8/17.
//  Copyright (c) 2017 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int debug,len,ans,arr[1002][5];

int cmp(int a,int b){
    if(arr[a][3] > arr[b][3]){
        return a;
    }
    else if(arr[a][3] < arr[b][3]){
        return b;
    }
    else{
        if(arr[a][4] > arr[b][4]){
            return a;
        }
        else if(arr[a][4] < arr[b][4]){
            return b;
        }
        else if(arr[a][4] == arr[b][4]){
            return min(a,b);
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/j-3/j-3/input.txt", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/j-3/j-3/ansSmall3.txt","w",stdout);
    int T,N,K,a1,a2,maxi;
    debug = 1;
    cin>>T;
    //T=1;
    for(int testCase=1;testCase<=T;testCase++){
        cin>>N>>K;
        arr[0][0]=arr[N+1][0]=1;
        for(int i=1;i<=N;i++){
            arr[i][0]=0;
            arr[i][1]=i-1;
            arr[i][2]=N-i;
            arr[i][3]=min(arr[i][1] , arr[i][2]);
            arr[i][4]=max(arr[i][1] , arr[i][2]);
        }
        for(int i=0;i<K;i++){
            int f =0;
            for(int j=1;j<=N;j++){
                if(arr[j][0]==0 && f==0){
                    maxi=j;
                    f=1;
                }
                else if(arr[j][0]==0 && f==1 ){
                    maxi = cmp(maxi,j);
                }
            }
            if(debug == 1){
                cout<<maxi<<endl;
            }
            arr[maxi][0]=1;
            for(int j=1;j<maxi;j++){
                arr[j][2]=min(maxi-j-1,arr[j][2]);
                arr[j][3]=min(arr[j][1] , arr[j][2]);
                arr[j][4]=max(arr[j][1] , arr[j][2]);
            }
            for(int j=maxi+1;j<=N;j++){
                arr[j][1]=min(j-maxi-1,arr[j][1]);
                arr[j][3]=min(arr[j][1] , arr[j][2]);
                arr[j][4]=max(arr[j][1] , arr[j][2]);
            }
        }
        cout<<"Case #"<<testCase<<": ";
        cout<<arr[maxi][4]<<" "<<arr[maxi][3]<<endl;
        
    }
    
    
}
