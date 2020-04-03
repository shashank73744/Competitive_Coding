//
//  main.cpp
//  Minimum_connected_component
//
//  Created by Shashank Saurabh on 26/09/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <fstream>
#include <ctime>

using namespace std;

int find(int u , int *boss)
{   int i=u;
    while (boss[i]!=i) {
        i=boss[i];
    }
    return i;
}

int union_ (int u, int v, int * boss, int *weight, int * update)
{
    int boss_u,boss_v,boss_;
    boss_u=find(u,boss);
    boss_v=find(v,boss);
    if (boss_u < boss_v)
    {
        boss[boss_v]=boss_u;
        weight[boss_u]=weight[boss_v] + weight [boss_u];
        update[boss_u]++;
        boss_=boss_u;
        
    }
    else if(boss_v < boss_u)
    {
        boss[boss_u]=boss_v;
        weight[boss_v]=weight[boss_u] + weight [boss_v];
        update[boss_v]++;
        boss_=boss_v;
        
    }
    return boss_;
}
class node
{
    public: int update, weight, boss;
    node(int x = -1,int y=-1,int z = -1):
        boss(x), weight(y) , update(z)
    {}
};
bool operator <(const node a,const node b)
{
    return(a.weight>b.weight);
}
using namespace std;
int main(int argc, const char * argv[]) {
    clock_t t1,t2;
    t1=clock();
    int N,Q;
    ifstream lemming;
    lemming.open("/Users/shashanksaurabh/Desktop/Journey/Minimum_connected_component/Minimum_connected_component/ans.txt");
    priority_queue<node> p ;
    lemming>>N>>Q;
    int weight[N],boss[N],update[N];
    for (int i=0; i<N; i++) {
        lemming>>weight[i];
        boss[i]=i;
        update[i]=0;
        p.push(node(i,weight[i],0));
    }
    for (int i=0; i<Q; i++) {
        int u ,v,boss_;
        lemming>>u>>v;
        u--;v--;
        boss_=union_(u, v, boss, weight, update);
        p.push(node(boss_, weight[boss_], update[boss_]));
        node n= p.top();
        while(!(boss[n.boss]==n.boss && n.update==update[n.boss]))
        {
            p.pop();
            n=p.top();
        }
        cout<<n.weight<<endl;
    }
    t2=clock();
    float time= ((float)t2 -(float)t1)/CLOCKS_PER_SEC;
    cout<<endl<<time;
    return 0;
}
