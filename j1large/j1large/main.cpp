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

int debug,len,f,ans;
char arr[1001];

void game (int pos , int nF){
    if(debug == 1){
        cout<<arr<<endl;
    }
    if(pos + f > len  ){
        int flag = 0;
        for(int i =0 ;i<len;i++){
            if(arr[i]=='-'){
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            ans = min(ans,nF);
        return;
    }
    if(arr[pos] == '-'){
        for(int j =0 ;j<f;j++){
            if( arr[pos+j] == '+')arr[pos+j]='-';
            else arr[pos+j]='+';
        }
        game (pos+1 , nF+1);
    }
    else{
        game (pos+1 , nF);
    }
    return;
    
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/j1large/j1large/A-large.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/j1large/j1large/ansSmall3.txt","w",stdout);
    int T;
    debug = 0;
    cin>>T;
    for(int testCase=1;testCase<=T;testCase++){
        cin>>arr;
        cin>>f;
        ans=1001;
        len = (int)strlen(arr);
        game(0,0);
        cout<<"Case #"<<testCase<<": ";
        if(ans == 1001)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<ans<<endl;
        
    }
    
    
}
