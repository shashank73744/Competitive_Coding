//
//  main.cpp
//  yu
//
//  Created by Shashank Saurabh on 29/11/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int s=36,n=9;
    for(int i=2;i<=n;i++)
    {
        if(s%i==0 && n%i==0)
        {
            s=s/i;
            n=n/i;
            i--;
        }
    }
    cout<<s<<"/"<<n;
    return 0;
}
