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
int matrix(int**mat2, int**mat,int size)
{
    int path_length=-1;
    clock_t t1,t2;
    for (int i=0; i<size; i++) {
        mat2[i]=new int[size];
        mat[i]=new int[size];
    }
    mat[size]=new int [size];
    mat[size+1]=new int [size];
    mat[size+2]=new int [size];
    mat[size+3]=new int [size];
    float density=.1;
    mat2=lee_generator(size,density);
    int si=rand()%size;
    int sj=rand()%size;
    int di=rand()%size;
    int dj=rand()%size;
    //cout<<si<<','<<sj<<endl;
    //cout<<di<<','<<dj<<endl;
    queue<int> p;
    mat2[si][sj]=-2;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            mat[i][j]=mat2[i][j];
        }
    }
    mat[di][dj]=-3;
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
            path_length=mat2[i][j-1];
            cout<<endl<<mat2[i+1][j];
        }
    }
    if(j+1<size&&mat2[i][j+1]==0){
        p.push(i);
        p.push(j+1);
        mat2[i][j+1]=mat2[i][j]+3;
        if ((i==di)&&j+1==dj) {
            path_length=mat2[i][j-1];
            cout<<endl<<mat2[i+1][j];
        }
    }
    if(i-1>-1&&mat2[i-1][j]==0){
        p.push(i-1);
        p.push(j);
        mat2[i-1][j]=mat2[i][j]+3;
        if ((i-1==di)&&j==dj) {
            path_length=mat2[i][j-1];
            cout<<endl<<mat2[i+1][j];
        }
    }
    if(j-1>-1&&mat2[i][j-1]==0){
        p.push(i);
        p.push(j-1);
        mat2[i][j-1]=mat2[i][j]+3;
        if ((i==di)&&j-1==dj) {
            path_length=mat2[i][j-1];
            cout<<endl<<mat2[i+1][j];
        }
    }
    
    
    while (!p.empty() && path_length==-1) {
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
                path_length=mat2[i+1][j];
                //cout<<endl<<mat2[i+1][j];
                break;
            }
        }
        if(j+1<size&&mat2[i][j+1]==0){
            p.push(i);
            p.push(j+1);
            mat2[i][j+1]=mat2[i][j]+1;
            if ((i==di)&&j+1==dj) {
                path_length=mat2[i][j+1];
                //cout<<endl<<mat2[i][j+1];
                break;
            }
        }
        if(i-1>-1&&mat2[i-1][j]==0){
            p.push(i-1);
            p.push(j);
            mat2[i-1][j]=mat2[i][j]+1;
            if ((i-1==di)&&j==dj) {
                path_length=mat2[i-1][j];
                //cout<<endl<<mat2[i-1][j];
                break;
            }
        }
        if(j-1>-1&&mat2[i][j-1]==0){
            p.push(i);
            p.push(j-1);
            mat2[i][j-1]=mat2[i][j]+1;
            if ((i==di)&&j-1==dj) {
                path_length=mat2[i][j-1];
                //cout<<endl<<mat2[i][j-1];
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
    
    int k = path_length-1;
    cout<<path_length+1<<endl;
    k=k/2;
    //cout<<k<<endl;
    int ci = di;
    int cj = dj;
    while (!(ci==si && cj==sj) ) {
        if(ci-1>-1 && (mat2[ci][cj] == mat2[ci-1][cj]+1 || mat2[ci-1][cj]==-2) && k>0)//down
        {
            ci=ci-1;
            k--;
            if(k==0)
            {
                mat[size][cj]=1;
                mat[size+1][ci]=1;
            }
            mat[ci][cj]=1;
        }
        else if(ci+1<size && (mat2[ci][cj] == mat2[ci+1][cj]+1 || mat2[ci+1][cj]==-2) && k>0 )//up
        {
            ci=ci+1;
            k--;
            if(k==0)
            {
                mat[size][cj]=1;
                mat[size+1][ci]=1;
            }
            
            mat[ci][cj]=1;
        }
        else if(cj+1 <size && (mat2[ci][cj] == mat2[ci][cj+1]+1 || mat2[ci][cj+1]==-2) && k>0  )//right
        {
            cj=cj+1;
            k--;if(k==0)
            {
                mat[size][cj]=1;
                mat[size+1][ci]=1;
            }
            
            mat[ci][cj]=1;
        }
        else if(cj-1 >-1 && (mat2[ci][cj] == mat2[ci][cj-1]+1 || mat2[ci][cj-1]==-2) && k>0)//left
        {
            cj=cj-1;
            k--;
            if(k==0)
            {
                mat[size][cj]=1;
                mat[size+1][ci]=1;
            }
            
            mat[ci][cj]=1;
        }
        else if(ci+1 < size && (mat2[ci][cj] == mat2[ci+1][cj]+1 || mat2[ci+1][cj]==-2) )//up
        {
            ci=ci+1;
            k--;
            if(k==-1)
            {
                mat[size+2][cj]=1;
                mat[size+3][ci]=1;
            }
            
            mat[ci][cj]=2;
        }
        else if(ci-1 >-1  && (mat2[ci][cj] == mat2[ci-1][cj]+1 || mat2[ci-1][cj]==-2) )//down
        {
            ci=ci-1;
            k--;
            if(k==-1)
            {
                mat[size+2][cj]=1;
                mat[size+3][ci]=1;
            }
            
            mat[ci][cj]=2;
        }
        else if(cj-1>-1 && (mat2[ci][cj] == mat2[ci][cj-1]+1 || mat2[ci][cj-1]==-2))//left
        {
            cj=cj-1;
            k--;
            if(k==-1)
            {
                mat[size+2][cj]=1;
                mat[size+3][ci]=1;
            }
            
            mat[ci][cj]=2;
        }
        else if(cj+1<size && (mat2[ci][cj] == mat2[ci][cj+1]+1 || mat2[ci][cj+1]==-2) )//right
        {
            cj=cj+1;
            k--;
            if(k==-1)
            {
                mat[size+2][cj]=1;
                mat[size+3][ci]=1;
            }
            
            mat[ci][cj]=2;
            
        }
        
    }
    mat[ci][cj]=-2;
    for (int i=0; i<size+4; i++) {
        cout<<endl;
        for (int j=0; j<size; j++) {
            cout<<mat[i][j]<<'\t';
        }
    }
    
    return path_length +1;
}

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    int size=5,path_length;
    int **mat2=new int*[size];
    int **mat=new int*[size+4];
    path_length=matrix(mat2,mat,size);
    
    return 0;
}
