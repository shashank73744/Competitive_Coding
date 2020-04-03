//
//  main.cpp
//  Mersene_prime
//
//  Created by Shashank Saurabh on 01/10/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

long modulo_operation( long mod, long n, int q )
{
    clock_t t1,t2;
    long long sum=1;
    long long num=n;
    int c=-1,top=0;
    queue<int> binary_places;
    while (q!=0) {
        c++;
        if(q%2==1)
            binary_places.push(c);
        q=q/2;
    }
    t1=clock();
    while (!binary_places.empty()) {
//----------------------------------------------------------------------------------------------------------
// Finding modulo of num*num
        for (int i=0; i<(binary_places.front()-top); i++)
        {
            
            long long num2 =num , sum2=0; long pow=1;
            if(num > 1000){
            while (num2!=0) {
                sum2=sum2 + (((num2%10)*num)%(mod/pow))*pow;
                sum2=sum2 % mod;
                num2=num2/10;
                pow=pow*10;
            }
                num=sum2;

            }
            else
            {
                num=(num*num)%mod;
            }
            cout<<num<<endl;
        }
//----------------------------------------------------------------------------------------------------------
// Finding modulo of num*sum
        long long num2 =num , sum2=0; long pow=1;
        if(num < 1000000000 && sum < 1000000000)
        {
            sum=(sum * num)% mod;
        }
        else
        {
        while (num2!=0) {
            sum2 = sum2 + (((num2%10)*sum)%(mod/pow))*pow;
            sum2=sum2 % mod;
            num2=num2/10;
            pow=pow*10;
        }
        }
        sum=sum2;
        cout<<sum<<endl;

//----------------------------------------------------------------------------------------------------------

        //cout<<sum<<endl;
            //sum=(num*sum)%modulo;
            top=binary_places.front();
            binary_places.pop();
    }
    t2=clock();

    float time=((float) t2 - (float)t1)/CLOCKS_PER_SEC;
    cout<<endl<<"time="<<(time*500000)<<endl;
    return sum;
}


int main(int argc, const char * argv[]) {
    clock_t t1,t2;
    ifstream lemming;
    lemming.open("/Users/shashanksaurabh/Desktop/Journey/Mersene_prime/Mersene_prime/ans.txt");
    int T;
    lemming>>T;
    long long aa=1000000000000000000;
    cout<<aa;
    int r1[12];
    long total=0,sum=0,mod=1000000000000;
    int a,b,c,d;
    t1=clock();
    for (int i=0; i<T; i++) {
        lemming>>a>>b>>c>>d;
        total=modulo_operation(mod,b, c);
        long num2=a,sum2=0,pow=1;
        while (num2!=0) {
            sum2 = sum2 + (((num2%10)*total)%(mod/pow))*pow;
            num2=num2/10;
            pow=pow*10;
            total=total;
        }
        sum=(sum +sum2 + d)%mod;
    }
    t2=clock();
    for (int i=0; i<12; i++) {
        r1[i]=sum%10;
        sum=sum/10;
    }
    for (int i=0; i<12; i++) {
        cout<<r1[11-i];
    }
    float time=((float) t2 - (float)t1)/CLOCKS_PER_SEC;
    cout<<endl<<"time="<<(time*500000);
    return 0;
}
