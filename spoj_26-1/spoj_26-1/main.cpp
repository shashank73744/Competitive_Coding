//
//  main.cpp
//  spoj_26-1
//
//  Created by Shashank Saurabh on 26/07/16.
//  Copyright (c) 2016 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
using namespace std;
int maxss[100][100];
int l1,l2;
int ss(int i,int j,char s1[],char s2[])
{
    if (i<0 || j<0) {
        return 0;
    }
    if(maxss[i][j]!=-1)
        return maxss[i][j];
    else{
        if(s1[i]==s2[j])
            maxss[i][j]= max(ss(i-1,j-1,s1,s2)+1,max(ss(i-1,j,s1,s2),ss(i,j-1,s1,s2)));
        else
            maxss[i][j]= max(ss(i-1,j,s1,s2),ss(i,j-1,s1,s2));
    }
    return maxss[i][j];
}

int main(int argc, const char * argv[]) {
    char sen[]="apple peach";
    char s1[]="ananas\0";
    char s2[]="banana\0";
    //freopen("input.txt", "r", stdin);
    //freopen("ans.txt", "w", stdout);
    
        l1=strlen(s1),l2=strlen(s2);
        for(int i=0;i<l1;i++)
        {
            for(int j=0;j<l2;j++)
            {
                maxss[i][j]=-1;
            }
        }
    cout<<ss(l1-1,l2-1,s1,s2);
    return 0;
}
