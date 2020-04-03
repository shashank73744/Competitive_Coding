//
//  main.cpp
//  Apac_gfiles
//
//  Created by Shashank Saurabh on 18/10/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int main(int argc, const char * argv[]) {
    freopen("/Users/shashanksaurabh/Desktop/Journey/Apac_gfiles/Apac_gfiles/test.txt","r",stdin);
    ofstream lemming;
    lemming.open("/Users/shashanksaurabh/Desktop/Journey/Apac_gfiles/Apac_gfiles/ans.txt");
    int T;
    long double p,f,ax;
    cin>>T;
    for (int ii=1; ii<=T; ii++) {
        long long N;
        cin>>N;
        long long max=0,min=1000000000000000,flag=0;
        for (int i=0; i<N; i++) {
            cin>>p>>f;
            if (p==100) {
                flag=f;
            }
            if(f!=0){
                ax=ceil((100*f)/(p+1));
                cout<<ax<<'\t';
                if(ax>max)
                    max=ax;
                ax=min;
                if(p!=0)
                    ax=floor(((100*f)/(p)));
                cout<<ax<<'\t'<<max<<'\t'<<min<<endl;
                if(ax<min)
                    min=ax;
            }
        }
        cout<<"Case #"<<ii<<": ";
        lemming<<"Case #"<<ii<<": ";
        long long r;
        if(flag==0){
        if (min==max) {
            r=min;
        }
        else
            r=-1;
        }
        else if (flag>0) {
            r=flag;
        }
        cout<<r<<endl;
        lemming<<r<<endl;
    }
    
    return 0;
}