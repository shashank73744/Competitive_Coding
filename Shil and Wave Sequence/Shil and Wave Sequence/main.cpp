//
//  main.cpp
//  Shil and Wave Sequence
//
//  Created by Shashank Saurabh on 9/17/17.
//  Copyright (c) 2017 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#define SIZE 200
using namespace std;


int getSum(int BITree[], int index)
{
    int sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;
    
    while (index <= n)
    {
        BITree[index] += val;
        
        index += index & (-index);
    }
}