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

int debug,len,ans,num[20];
char arr[20];

void func1(int pos){
    --len;
    for(int i=0;i<len;i++){
        num[i]=9;
    }
}

void func2(int pos){
    int c=pos-1, trend;
    while(arr[c]==1 ){
        num[c]=9;
        --c;
    }
    trend = arr[c];
    while(c>=0 &&arr[c]==trend ){
        --num[c];
        --c;
    }
    for(int i=c+2;i<len;i++){
        num[i]=9;
    }
}

void func3(int pos){
    int c=pos-1, trend=arr[pos-1];
    while(c>=0 &&arr[c]==trend ){
        --num[c];
        --c;
    }
    for(int i=c+2;i<len;i++){
        num[i]=9;
    }
}

int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/J-2/J-2/B-large.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/J-2/J-2/ansSmall.txt","w",stdout);
    int T,trend,start;
    debug = 0;
    cin>>T;
    for(int testCase=1;testCase<=T;testCase++){
        cin>>arr;
        len= (int)strlen(arr);
        for(int i =0 ;i<len;i++){
            num[i]=arr[i]-'0';
        }
        trend = num[0];
        start = num[0];
        for(int i= 1;i<len;i++){
            if(start == 1 && trend ==1){
                if(num[i] < trend ){
                    func1(i);
                    break;
                }
            
            }
            else if (trend == 1 ){
                if(num[i] < trend){
                    func2(i);
                    break;
                }
            
            }
            else if (trend !=1){
                if(num[i] < trend){
                    func3(i);
                    break;
                }
            }
            trend =num[i];
            
        }
        
        cout<<"Case #"<<testCase<<": ";
        for(int i =0 ;i<len;i++){
            cout<<num[i];
        }
        cout<<endl;
    }
    
    
}
