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

int debug,len,ans,num[20],n;
char arr[20];

bool tidy(int nu){
    int count=-1,trend;
    //        for(int i =0 ;i<len;i++){
    //            cout<<num[i];
    //        }
    while(nu!=0){
        ++count;
        num[count] = nu % 10;
        //cout<<num[count];
        nu=nu /10;
    }
//    for(int i =0 ;i<=count;i++){
//        cout<<num[i];
//    }
    trend=num[count];
    for(int i = count-1;i>=0;i--){
        if(num[i]<trend){
            return false;
        }
        trend = num[i];
    }
    return true;
}
int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/j-2-test/j-2-test/B-small-attempt1.in", "r",stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/j-2-test/j-2-test/ansSmall.txt","w",stdout);
    int T;
    debug = 0;
    cin>>T;
    for(int testCase=1;testCase<=T;testCase++){
        cin>>n;
        for(int i =n;i>=0;i--){
            if(tidy(i) == true){
                ans = i;
                break;
            }
        }
        cout<<"Case #"<<testCase<<": ";
//        for(int i =0 ;i<len;i++){
//            cout<<num[i];
//        }
        cout<<ans;
        cout<<endl;
    }
    
    
}
