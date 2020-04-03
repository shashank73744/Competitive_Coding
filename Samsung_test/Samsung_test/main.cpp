//
//  main.cpp
//  Samsung_test
//
//  Created by Shashank Saurabh on 07/07/16.
//  Copyright (c) 2016 Shashank Saurabh. All rights reserved.
//

#include <iostream>

using namespace std;
int C[]={1,2,4,5,6,7,8,9};
int store[6],len=6;
void Combination (int index , int str_len,int size,int pos );
int main(int argc, const char * argv[]) {
    	Combination (0, 6 ,8,0);
        return 0;
}
void Combination (int index , int str_len,int size ,int pos)
{
    if (str_len> size-index || str_len==0) {
        cout<<endl;
        return;
    }
    else
    {
        store[pos]=C[index];
        Combination (index+1 , str_len-1 ,size,pos+1);
        Combination(index+1, str_len,size,pos);
    }
    return;
}
