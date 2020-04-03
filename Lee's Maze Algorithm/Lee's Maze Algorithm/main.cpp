//
//  main.cpp
//  Lee's Maze Algorithm
//
//  Created by Shashank Saurabh on 4/1/15.
//  Copyright (c) 2015 Shashank Saurabh. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <queue>

using namespace std;
double prob(){
    return(static_cast<double>(rand())/2147483647);
}
int** lee_generator(int size,double density)
{
    int **mat=new int *[size];
    for (int i=0; i<size; i++) {
        mat[i]=new int[size];
    }
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            mat[i][j]=prob()>density?0:-1;
        }
    }
    return mat;
}

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    int size=10;
    clock_t t1,t2;
    int **mat2=new int*[size];
    for (int i=0; i<size; i++) {
        mat2[i]=new int[size];
    }
    float density=.05;
    mat2=lee_generator(size,density);
   /* for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            scout<<mat[i][j]<<" ";
            mat2[i][j]=mat[i][j];
        }
        cout<<endl;
    }*/
    int si=rand()%size;
    int sj=rand()%size;
    int di=rand()%size;
    int dj=rand()%size;
    cout<<si<<','<<sj<<endl;
    cout<<di<<','<<dj<<endl;
    queue<int> p;
    mat2[si][sj]=-2;
    
    t1=clock();//time starts from here
    p.push(si);
    p.push(sj);
    int i,j;
    i=p.front();
    p.pop();
    j=p.front();
    p.pop();
    if( i+1<size&&mat2[i+1][j]==0){
        p.push(i+1);
        p.push(j);
        mat2[i+1][j]=mat2[i][j]+3;
        if ((i+1==di)&&j==dj) {
        }
    }
    if(j+1<size&&mat2[i][j+1]==0){
        p.push(i);
        p.push(j+1);
        mat2[i][j+1]=mat2[i][j]+3;
        if ((i==di)&&j+1==dj) {
        }
    }
    if(i-1>-1&&mat2[i-1][j]==0){
        p.push(i-1);
        p.push(j);
        mat2[i-1][j]=mat2[i][j]+3;
        if ((i-1==di)&&j==dj) {
        }
    }
    if(j-1>-1&&mat2[i][j-1]==0){
        p.push(i);
        p.push(j-1);
        mat2[i][j-1]=mat2[i][j]+3;
        if ((i==di)&&j-1==dj) {
        }
    }

    
    while (!p.empty()) {
        int i,j;
        i=p.front();
        p.pop();
        j=p.front();
        p.pop();
        if( i+1<size&&mat2[i+1][j]==0){
            p.push(i+1);
            p.push(j);
            mat2[i+1][j]=mat2[i][j]+1;
            if ((i+1==di)&&j==dj) {
                cout<<endl<<mat2[i+1][j];
                break;
            }
        }
        if(j+1<size&&mat2[i][j+1]==0){
            p.push(i);
            p.push(j+1);
            mat2[i][j+1]=mat2[i][j]+1;
            if ((i==di)&&j+1==dj) {
                cout<<endl<<mat2[i][j+1];
                break;
            }
        }
        if(i-1>-1&&mat2[i-1][j]==0){
            p.push(i-1);
            p.push(j);
            mat2[i-1][j]=mat2[i][j]+1;
            if ((i-1==di)&&j==dj) {
                cout<<endl<<mat2[i-1][j];
                break;
            }
        }
        if(j-1>-1&&mat2[i][j-1]==0){
            p.push(i);
            p.push(j-1);
            mat2[i][j-1]=mat2[i][j]+1;
            if ((i==di)&&j-1==dj) {
                cout<<endl<<mat2[i][j-1];
                break;
            }
        }
    }
    /*for (int i=0; i<size; i++) {
        cout<<endl;
        for (int j=0; j<size; j++) {
            cout<<mat2[i][j]<<'\t';
        }
    }*/
    t2 = clock();
    float diff((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cout<<seconds<<endl;
    return 0;
}
