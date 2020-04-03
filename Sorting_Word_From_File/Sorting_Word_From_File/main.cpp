//
//  main.cpp
//  Sorting_Word_From_File
//
//  Created by Shashank Saurabh on 2/23/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
void getw(string &t, ifstream &in){
    in>>t;
}
int input(vector<string> &v,ifstream &in ){
    int i=0;
    while (!in.eof()) {
        getw(v[i++],in);
    }
    return i-1;
}
int main() {
    int i;
    ifstream in("data");
    vector<string> v(1000);
    i=input(v,in);
    v.resize(i);
    sort(v.begin(),v.end());
    for (auto str: v) {
        cout<<str<<'\t';
    }
    return 0;
}
