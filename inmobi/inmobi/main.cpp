//
//  main.cpp
//  inmobi
//
//  Created by Shashank Saurabh on 29/11/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
        int n ,s=0;
        //cin>>n;
        int a[7]={1 , 2 , 3 , 40 , 52 , 33 , 86};
        /*for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }*/
        for(int i=0;i<7;i++)
        {
            for(int j=i+1;j<7;j++)
            {
                int k=a[i]-a[j];
                if(k<0)
                    k=k*-1;
                s=s+k;
            }
        }
        cout<<s*2;
    return 0;
}
