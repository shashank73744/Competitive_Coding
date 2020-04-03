//
//  main.cpp
//  Journey
//
//  Created by Shashank Saurabh on 1/12/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

class edge{
public:
    long weight;
    unsigned long point;
    
};
class node{
    int id;
public:
    std::vector<edge> edges;
};
class graph{
    std::vector<node> nodes;
    unsigned long size=this->nodes.size();
    void joinwt(unsigned long p, unsigned long q, long wt){
        unsigned long r,size=this->nodes[p].edges.size();
        while (r<size && this->nodes[p].edges[r].point!=q) {
            r++;
        }
        if (r!=size) {
            this->nodes[p].edges[r].weight=wt;
        }
        else{
            
        }
    }
}

int main()
{
    
}