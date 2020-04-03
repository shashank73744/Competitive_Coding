//
//  main.cpp
//  Trouble Sort
//
//  Created by Shashank Saurabh on 4/7/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Trouble Sort/Trouble Sort/input.txt", "r", stdin);
    freopen("/Users/shashanksaurabh/Desktop/Journey/Trouble Sort/Trouble Sort/output.txt", "w", stdout);
    long *V0,init=0, *V1;
    V0 = new long[100000];
    V1 = new long[100000];
    int T,N=0,ans=-1;
    cin>>T;
    for (int i=1; i<=T; i++) {
        ans=-1;
        cin>>N;
        for (int j=0; j<N; j++) {
            if(j%2==0)cin>>V0[j/2];
            else cin>>V1[j/2];
        }
    sort(V0,V0+(N+1)/2);
    sort(V1,V1+N/2);
    init = V0[0];
        for (int j=0; j<N; j++) {
            if(j%2==0){
                if (V0[j/2]<init) {ans=j;break;}
                init = V0[j/2];
            }
            else{
                if(V1[j/2] < init){ans =j;break;}
                init = V1[j/2];
            }
        }
    if(ans == -1)
        cout<<"Case #"<<i<<": "<<"OK"<<endl;
    else
        cout<<"Case #"<<i<<": "<<ans-1<<endl;
    }
    return 0;
}
