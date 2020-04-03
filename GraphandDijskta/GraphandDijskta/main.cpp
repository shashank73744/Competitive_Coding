//
//  main.cpp
//  GraphandDijskta
//
//  Created by Shashank Saurabh on 2/3/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <queue>
int * dis;
using namespace std;
double prob(){
        double num = static_cast<double>(rand())/2147483647;
    return num;
}//Returns a random number between 0 and 1
class path {
public:
    int s,d,w;
    path():d(0), w(0),s(0){}
    path(int s, int d, int w):s(s),d(d),w(w){}
    path(path *cpy){
        s=cpy->s;
        d=cpy->d;
        w=cpy->w;
    }

};//path has source(s),destination(d)and weight(w)
bool operator<(path a , path b){ // for overloading the < operator for implementation of priority_queue
    return (a.w + dis[a.s] < b.w + dis[b.s] ? false:true);
}
vector<list<path>> graphgenerator(int size){
    vector<list<path>> a;
    a.resize(size);
    list<path> p;
    int **g=new int*[size];
    for (int i=0; i<size; i++) {
        g[i]= new int[size];
    }
    for (int i=0; i<size; i++) {
        for (int j=i; j<size;j++) {
            if(i!=j) {
                if(prob()>.80){
                    g[i][j]=g[j][i]=0;
                }
                else{
                    g[i][j]=g[j][i]=rand()%56;
                    a[i].push_back(path(i,j,g[i][j]));
                    a[j].push_back(path(j,i,g[i][j]));
                }
            }
        }
    }
    return a;
}// This generates a random graph

int* Djikstra(vector<list<path>> graph){
    
    unsigned long size=graph.size();
    int* shortestdistance=new int[size];
    dis=shortestdistance;
    shortestdistance[0]=0;
    for (int i=1; i<size; i++) {
        shortestdistance[i]=-1;
    }
    priority_queue<path> q;
    list<path>::iterator itr = graph[0].begin();
    while (itr!=graph[0].end()) {
        path a = new path(*itr);
        q.push(a);
        ++itr;
    }
    int r=0;
    while (r<size && !q.empty()) {
        path b,c;
        b=q.top();
        cout<<b.s<<" "<<b.d<<" "<<b.w<<endl;
        shortestdistance[b.d]=shortestdistance[b.s]+b.w;
        q.pop();
        list<path>::iterator itr = graph[b.d].begin();
        while (itr!=graph[b.d].end()) {
            if (shortestdistance[itr->d]==-1) {
                c = new path(*itr);
                q.push(c);
            }
            ++itr;
            
        }
        while (shortestdistance[(q.top()).d]!=-1 && !q.empty()) {
            q.pop();
        }
        r++;
    }
    return shortestdistance;
}// This takes a graph and returns an array with minimum distance to each node(array index is denotes the node).

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    int size=4;
    vector<list<path>> graph;//graph is a vetor of list. 
    graph=graphgenerator(size);
    for (int i=0; i<size; i++) {
        auto itr = graph[i].begin();
        while (itr!=graph[i].end()) {
            cout<<"  ("<<itr->s<<","<<itr->d<<","<<itr->w<<")  ";
            ++itr;
        }
        cout<<endl;
    }
    int* shortestdistance=new int[size];
    shortestdistance=Djikstra(graph);
    for (int i=0; i<size; i++) {
        cout<<shortestdistance[i]<<endl;
    }
        return 0;
}
