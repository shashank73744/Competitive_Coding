//
//  main.cpp
//  Go, Gopher!
//
//  Created by Shashank Saurabh on 4/8/18.
//  Copyright (c) 2018 Shashank Saurabh. All rights reserved.
//

#include <iostream>

using namespace std;

bool check(int garden[7][3], int pos){
    for (int i=0; i<=2; i++) {
        if (garden[pos][i] == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int garden[7][3],x,y,T,A,testcase;
    bool done =false;
    cin>>testcase;
    for (int testcase=1; testcase<=T; ++testcase) {
        cin>>A;
        done=false;
        for (int i=0; i<7; i++) {
            for (int j=0; j<3; j++) {
                garden[i][j]=0;
            }
        }
        for (int i=1; i<=5; i++) {
            while (check(garden,(i-1))) {
                cout<<i+10<<" "<<11<<endl;
                cin>>x>>y;
                if(x==0 && y==0){
                    done = true;
                    break;
                }
                garden[x-10][y-10]=1;
                
            }
            if(done)break;
        }
        if (done) {
            continue;
        }
        do{
            cout<<15<<" "<<11<<endl;
            cin>>x>>y;
        }while (!(x==0 && y==0));
        
    }
    return 0;
}
